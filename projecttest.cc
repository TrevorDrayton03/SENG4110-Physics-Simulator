/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/
#include "simulation.h"
#include "gtest/gtest.h"
/*
Equivalence Classes:
G1: {gravity: 0 < gravity <= 100.0}
G2: {gravity: 0}

A1: {angle: 0 < angle <= 90.0}
A2: {angle: 0}

H1: {height: 0 < height <= 100.0}
H2: {height: < 0}

Equivalence Classes of invalid values:
G3: {gravity < 0}
G3: {gravity > 100.0}

A3: {angle < 0}
A4: {angle > 90.0}

H3: {height < 0}
H4: {height > 100.0}
*/
/**
*	PATHS
*	incorrect number of args
*
*	args correct -> valid type -> rock -> grav is zero || height & angle both are zero -> end
*	args correct -> valid type -> glass -> grav is zero || height & angle both are zero -> end
*	args correct -> invalid type -> iron -> grav is zero || height & angle both are zero -> end
*	args correct -> valid type -> iron -> grav is zero || height & angle both are zero -> end
*
*	args correct -> valid type -> rock -> has height -> end
*	args correct -> valid type -> glass -> has height -> end
*	args correct -> invalid type -> iron -> has height -> end
*	args correct -> valid type -> iron -> has height -> end
*
*	args correct -> valid type -> rock -> has no height -> end
*	args correct -> valid type -> glass -> has no height -> end
*	args correct -> invalid type -> iron -> has no height -> end
*	args correct -> valid type -> iron -> has no height -> end
*
*	Test coverage includes Gnode, Gedge, Gchain and Gpath
*/
/**
*
* Dataflow
* All-Defs, All-Uses All-P-Uses
* Each possible definition and use combination is tested for in the PathTesting
*
*/
using namespace projectlib;
/**
* Unit test function for Simulation::getTimeTakenToLand()
* @see Simulation::getTimeTakenToLand()
*
*/
double getTimeTakenToLand(double angleInDegreesInput, double vyInput, double gravityInput, double heightInput) {
	double angleInDegrees = angleInDegreesInput;
	double vy = vyInput;
	double gravity = gravityInput;
	double height = heightInput;
	double timeToLand;
	if (gravity == MIN_GRAVITY || (height == MIN_HEIGHT && angleInDegrees == MIN_ANGLE))
	{
		timeToLand = 0.0;
		return timeToLand;
	}
	if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
		height = NOMINAL_HEIGHT;
	}
	if (angleInDegrees < MIN_ANGLE || angleInDegrees > MAX_ANGLE) {
		angleInDegrees = NOMINAL_ANGLE;
	}
	if (gravity < MIN_GRAVITY || gravity > MAX_GRAVITY) {
		gravity = NOMINAL_GRAVITY;
	}
	if (height > MIN_HEIGHT)
	{
		timeToLand = (vy + sqrt((pow(vy, 2.0) + 2.0 * gravity * height))) / gravity;
	}
	else {
		timeToLand = (2.0 * vy) / gravity;
	}
	return timeToLand;
}

/**
* Integration test function for Simulation::getTimeTakenToLand().
* @see Simulation::getTimeTakenToLand()
*
*/
double getTimeTakenToLand(Cannonball cannonball, Cannon cannon, double gravityInput) {
	double angleInDegrees = cannon.getAngle() * DEGREE_TO_RADIAN_CONVERSION;
	double vy = sin(angleInDegrees) * cannonball.getInitialVelocity();
	double gravity = gravityInput;
	double height = cannon.getHeight();
	double timeToLand;
	if (gravity == MIN_GRAVITY || (height == MIN_HEIGHT && angleInDegrees == MIN_ANGLE))
	{
		timeToLand = 0.0;
		return timeToLand;
	}
	if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
		height = NOMINAL_HEIGHT;
	}
	if (angleInDegrees < MIN_ANGLE || angleInDegrees > MAX_ANGLE) {
		angleInDegrees = NOMINAL_ANGLE;
	}
	if (gravity < MIN_GRAVITY || gravity > MAX_GRAVITY) {
		gravity = NOMINAL_GRAVITY;
	}
	if (height > MIN_HEIGHT)
	{
		timeToLand = (vy + sqrt((pow(vy, 2.0) + 2.0 * gravity * height))) / gravity;
	}
	else {
		timeToLand = (2.0 * vy) / gravity;
	}
	return timeToLand;
}

/*
*
*
* UNIT TESTS
*
* 
*/
TEST(UnitTesting, RobustBoundaryValueUnitTest) {
	double gravityInput, heightInput, angleInput;

	double robustTestCases[19][3] = {
		{MIN_MINUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MIN_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MIN_PLUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_MINUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_PLUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_MINUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_PLUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_MINUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_PLUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_MINUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_PLUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_MINUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_PLUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE}
	};

	double correctResults[19] = {
		21.6846,0,212.095,2.18806,2.16663,21.6846,21.6846,21.6375,21.6469,22.5341,
		22.5428,21.6846,0.777848,1.01015,1.31183,30.6405,30.6455,30.6413,21.6846
	};
	for (int i = 0; i < 19; i++) {
		gravityInput = robustTestCases[i][0];
		heightInput = robustTestCases[i][1];
		angleInput = robustTestCases[i][2] * DEGREE_TO_RADIAN_CONVERSION;
		double vyInput = sin(angleInput) * IRON_INITIAL_VELOCITY;
		double time = getTimeTakenToLand(angleInput, vyInput, gravityInput, heightInput);
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}

TEST(UnitTesting, StrongNormalEquivalenceUnitTest) {
	double gravityInput, heightInput, angleInput;

	double testCases[8][3] = {
		{5.0, 30.0, 0.0}, {5.0, 30.0, 0.0}, {5.0, 0.0, 5.0}, {5.0, 0.0, 0.0},
		{0.0, 30.0, 5.0}, {0.0, 30.0, 0.0}, {0.0, 0.0, 5.0}, {0.0, 0.0, 0.0}
	};

	double correctResults[8] = {
		3.4641,3.4641,5.2267,0,0,0,0,0
	};

	for (int i = 0; i < 8; i++) {
		gravityInput = testCases[i][0];
		heightInput = testCases[i][1];
		angleInput = testCases[i][2] * DEGREE_TO_RADIAN_CONVERSION;
		double vyInput = sin(angleInput) * IRON_INITIAL_VELOCITY;
		double time = getTimeTakenToLand(angleInput, vyInput, gravityInput, heightInput);
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}
/**
* 
* In this case, the Limited Decision Table is identical to the Strong Normal Equivalence Unit Test.
* This test is the Reduced Decision Table test.
* 
*/
TEST(UnitTesting, ReducedDecisionTableUnitTest) {
	double gravityInput, heightInput, angleInput;

	double testCases[3][3] = {
		{5.0, 30.0, 5.0}, {5.0, 0.0, 0.0}, {0.0, 30.0, 5.0}
	};

	double correctResults[3] = {
		6.95266,0,0
	};

	for (int i = 0; i < 3; i++) {
		gravityInput = testCases[i][0];
		heightInput = testCases[i][1];
		angleInput = testCases[i][2] * DEGREE_TO_RADIAN_CONVERSION;
		double vyInput = sin(angleInput) * IRON_INITIAL_VELOCITY;
		double time = getTimeTakenToLand(angleInput, vyInput, gravityInput, heightInput);
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}
TEST(UnitTesting, PathTest) {
	double gravityInput, heightInput, angleInput;
	std::string typeInput;
	std::string testCase;

	std::string testCases[18] = {
		"0 rock 30.0 5.0", "9.8 glass 0 0", "0 book 30.0 5.0", "9.8 iron 0.0 0.0",
		"9.8 rock 30.0 5.0", "9.8 glass 0 10.0", "14.9 book 30.0 5.0", "9.8 iron 0.0 10.0",
		"0 rock 30.0 0.0", "9.8 glass 45.0 0", "0 book 30.0 0.0", "9.8 iron 60.0 0.0"
	};

	double correctResults[18] = {
		0,0,0,0,3.51907,4.25047,3.06692,5.31309,0,3.03046,0,3.49927,3.49927,
		3.49927,3.49927,3.49927,3.49927,3.49927
	};
	for (int i = 0; i < 18; i++) {
		std::istringstream sin(testCases[i]);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		double initialVelocity;
		if (typeInput == "rock")
		{
			initialVelocity = ROCK_INITIAL_VELOCITY;
		}
		else if (typeInput == "glass")
		{
			initialVelocity = GLASS_INITIAL_VELOCITY;
		}
		else
		{
			initialVelocity = IRON_INITIAL_VELOCITY;
		}
		angleInput = angleInput * DEGREE_TO_RADIAN_CONVERSION;
		double vyInput = std::sin(angleInput) * initialVelocity;
		double time = getTimeTakenToLand(angleInput, vyInput, gravityInput, heightInput);
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}
/**
* Admittedly, the following slice test suite is a system test, not unit tests as they should be.
*/
TEST(UnitTesting, Slice22) {
	Simulation simulation = simulation.Pre_Slice();
	EXPECT_NEAR(simulation.Slice22(simulation), 0.52, .1);
}
TEST(UnitTesting, Slice23) {
	Simulation simulation = simulation.Pre_Slice();
	EXPECT_NEAR(simulation.Slice23(simulation), 75, .1);
}
TEST(UnitTesting, Slice24) {
	Simulation simulation = simulation.Pre_Slice();
	EXPECT_EQ(simulation.Slice24(simulation), 9.8);
}
TEST(UnitTesting, Slice25) {
	Simulation simulation = simulation.Pre_Slice();
	EXPECT_EQ(simulation.Slice25(simulation), 0);
}
TEST(UnitTesting, Slice26) {
	Simulation simulation = simulation.Pre_Slice();
	EXPECT_EQ(simulation.Slice26(), 0);
}
TEST(UnitTesting, Slice27) {
	Simulation simulation = simulation.Pre_Slice();
	double gravity = 0;
	double height = 1.0;
	double angleInDegrees = 30.0;
	EXPECT_EQ(simulation.Slice27(gravity, height, angleInDegrees), 0);
}
TEST(UnitTesting, Slice32) {
	Simulation simulation = simulation.Pre_Slice();
	double height = -1.0;
	EXPECT_EQ(simulation.Slice32(height), 5.0);
}
TEST(UnitTesting, Slice35) {
	Simulation simulation = simulation.Pre_Slice();
	double angle = 145.0;
	EXPECT_EQ(simulation.Slice35(angle), 45.0);
}
TEST(UnitTesting, Slice38) {
	Simulation simulation = simulation.Pre_Slice();
	double gravity = -5.0;
	EXPECT_EQ(simulation.Slice38(gravity), 9.8);
}
TEST(UnitTesting, Slice41) {
	Simulation simulation = simulation.Pre_Slice();
	double height = 10.0;
	double vy = simulation.Slice23(simulation);
	double gravity = simulation.Slice24(simulation);
	EXPECT_NEAR(simulation.Slice41(height, gravity, vy), 15.4, .1);
}
TEST(UnitTesting, Slice45) {
	Simulation simulation = simulation.Pre_Slice();
	double vy = simulation.Slice23(simulation);
	double gravity = simulation.Slice24(simulation);
	EXPECT_NEAR(simulation.Slice45(vy, gravity), 15.2, .1);
}

/**
*
*
*
* SYSTEM TESTS
*
*
*/
TEST(SystemTesting, RobustBoundaryValueSystemTest) {
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	double robustTestCases[19][3] = {
		{MIN_MINUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MIN_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MIN_PLUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_MINUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{MAX_PLUS_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_MINUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MIN_PLUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_MINUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, MAX_PLUS_HEIGHT, NOMINAL_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_MINUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MIN_PLUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_MINUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, MAX_PLUS_ANGLE},
		{NOMINAL_GRAVITY, NOMINAL_HEIGHT, NOMINAL_ANGLE}
	};

	double correctResults[19] = { 
		212.095,0,212.095,2.18806,2.16663,21.6846,21.6846,21.6375,21.6469,22.5341,
		22.5428,21.6846,0.777848,1.01015,1.31183,30.6405,30.6455,30.6413,21.6846 
	};
	simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
	for (int i = 0; i < 19; i++) {
		// loop through each robust test case and insert the values into istringstream
		testCase = testCase + std::to_string(robustTestCases[i][0]) + " ";
		testCase = testCase + "iron ";
		testCase = testCase + std::to_string(robustTestCases[i][1]) + " ";
		testCase = testCase + std::to_string(robustTestCases[i][2]);
		std::istringstream sin(testCase);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		double time = simulation.getTimeTakenToLand();
		testCase = "";
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}

/** 
* Strong Normal because there is a situation where when angle and height are 0 then we get an output of 0.
*/
TEST(SystemTesting, StrongNormalEquivalenceSystemTest) {
	// 8 cases, 2*2*2
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[8] = {
		"5.0 iron 30.0 0.0", "5.0 iron 30.0 0.0", "5.0 iron 0.0 5.0", "5.0 iron 0.0 0.0",
		"0.0 iron 30.0 5.0", "0.0 iron 30.0 0.0", "0.0 iron 0.0 5.0", "0.0 iron 0.0 0.0"
	};

	double correctResults[8] = {
		3.4641,3.4641,5.2267,0,0,0,0,0
	};

	for (int i = 0; i < 8; i++) {
		testCase = testCases[i];
		std::istringstream sin(testCase);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		double time = simulation.getTimeTakenToLand();
		testCase = "";
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}

TEST(SystemTesting, ReducedDecisionTableSystemTest) {
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[3] = {
		"5.0 iron 30.0 5.0", "5.0 iron 0.0 0.0", "0.0 iron 30.0 5.0",
	};

	double correctResults[3] = {
		6.95266,0,0
	};

	for (int i = 0; i < 3; i++) {
		testCase = testCases[i];
		std::istringstream sin(testCase);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		double time = simulation.getTimeTakenToLand();
		testCase = "";
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}

TEST(SystemTesting, MMPathTesting) {
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[19] = {
		"9.8 rock",
		"0 rock 30.0 5.0", "9.8 glass 0 0", "0 book 30.0 5.0", "9.8 iron 0.0 0.0",
		"9.8 rock 30.0 5.0", "9.8 glass 0 10.0", "14.9 book 30.0 5.0", "9.8 iron 0.0 10.0",
		"0 rock 30.0 0.0", "9.8 glass 45.0 0", "0 book 30.0 0.0", "9.8 iron 60.0 0.0"
	};

	double correctResults[19] = {
		0,0,0,0,0,3.51907,4.25047,2.67477,5.31309,0,3.03046,0,3.49927,3.49927,
		3.49927,3.49927,3.49927,3.49927,3.49927
	};

	for (int i = 0; i < 19; i++) {
		testCase = testCases[i];
		std::istringstream sin(testCase);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		double time = simulation.getTimeTakenToLand();
		testCase = "";
		EXPECT_NEAR(time, correctResults[i], .1);
	}
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
