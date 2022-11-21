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
	//std::istringstream sin("10 2 3 -1");
	//std::cin.rdbuf(sin.rdbuf());

	double gravityInput, diameterInput, heightInput, angleInput, velocityInput;
	std::string typeInput;

	std::cout << "Welcome to the Physics Simulator. \n";
	std::cout << "Enter the value for gravity. \n";
	std::cin >> gravityInput;
	std::cout << "Enter the type of cannonball (iron, rock, or glass). \n";
	std::cin >> typeInput;
	std::cout << "Enter the value for the diameter of the cannonball (centimeters). \n";
	std::cin >> diameterInput;
	std::cout << "Enter the value for the height of the cannon (centimeters). \n";
	std::cin >> heightInput;
	std::cout << "Enter the value for the angle of the cannon. \n";
	std::cin >> angleInput;
	std::cout << "Enter the value for the initial speed of the cannonball (m/s). \n";
	std::cin >> velocityInput;
	std::cout << "Running the simulation...\n";

	Simulation simulation = Simulation(gravityInput, heightInput, diameterInput, angleInput, velocityInput, typeInput);
	double time = simulation.getVerticalDistanceTravelled();
	std::cout <<"It took " << time << " seconds to initially strike the ground."
};