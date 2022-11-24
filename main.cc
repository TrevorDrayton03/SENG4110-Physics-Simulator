/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

using namespace projectlib;
int main(int argc, char** argv)
{
	double gravityInput, heightInput, angleInput;
	Simulation simulation;
	std::string typeInput;
	std::string testCase;

	std::string testCases[8] = {
		"5.0 iron 30.0 5.0", "5.0 iron 30.0 0.0", "5.0 iron 0.0 5.0", "5.0 iron 0.0 0.0",
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
		std::cout << time << "\n";
		//EXPECT_NEAR(time, correctResults[i], .1);
	}
};