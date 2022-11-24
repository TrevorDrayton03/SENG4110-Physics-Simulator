/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

using namespace projectlib;
int main(int argc, char **argv)
{
	// gravity, type, height, angle
	//std::istringstream sin("9.8 iron 100.0 30.0 ");
	//std::cin.rdbuf(sin.rdbuf());

	//double gravityInput, heightInput, angleInput;
	//std::string typeInput;

	//std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;

	//Simulation simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
	//double time = simulation.getTimeTakenToLand();
	//std::cout << "It took " << time << " seconds for the " <<simulation.getType()<<" cannonball to strike the ground. \n";
	//double gravityInput, heightInput, angleInput;
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[8] = {
		"5.0 iron 30.0 0.0", "5.0 iron 30.0 0.0", "5.0 iron 0.0 5.0", "5.0 iron 0.0 0.0",
		"0.0 iron 30.0 5.0", "0.0 iron 30.0 0.0", "0.0 iron 0.0 5.0", "0.0 iron 0.0 0.0"
	};

	for (int i = 0; i < 8; i++) {
		testCase = testCases[i];
		std::istringstream sin(testCase);
		std::cin.rdbuf(sin.rdbuf());
		std::cin >> gravityInput >> typeInput >> heightInput >> angleInput;
		simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		double time = simulation.getTimeTakenToLand();
		std::cout << time << "\n";
		testCase = "";
		//EXPECT_NEAR(time, correctResults[i], .1);
	}
};