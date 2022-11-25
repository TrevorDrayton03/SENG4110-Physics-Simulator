/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/
#include "simulation.h"
#include "cannon.h"
#include "cannonball.h"
#include "gtest/gtest.h"

using namespace projectlib;

/*
This file performs the following tests on simulation.cc:
	 Robust Boundary Value
	 Equivalence Class
*/
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
TEST(BoundaryValue, Robust) {
	// include type in the boundary?
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
* 
* 
* Strong Normal because there is a situation where when angle and height are 0 then we get an output of 0.
* 
* 
*/
TEST(Equivalence, StrongNormal) {
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
TEST(DecisionTable, Limited) {
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[8] = {
		"5.0 iron 30.0 5.0", "5.0 iron 30.0 0.0", "5.0 iron 0.0 5.0", "5.0 iron 0.0 0.0",
		"0.0 iron 30.0 5.0", "0.0 iron 30.0 0.0", "0.0 iron 0.0 5.0", "0.0 iron 0.0 0.0"
	};

	double correctResults[8] = {
		6.95266,3.4641,5.2267,0,0,0,0,0
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

TEST(DecisionTable, Reduced) {
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

TEST(PathTesting, Reduced) {
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
