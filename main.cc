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
	//std::istringstream sin("9.8 iron 10 100 30 5");
	// gravity, type, diameter, height, angle, velocity
	std::istringstream sin("9.8 iron 10.0 1.0 30.0 80.0");
	std::cin.rdbuf(sin.rdbuf());

	double gravityInput, diameterInput, heightInput, angleInput, velocityInput;
	std::string typeInput;

	std::cout << "Welcome to the Physics Simulator. \n";
	std::cout << "Enter the value for gravity (N/kg). \n";
	std::cin >> gravityInput;
	std::cout << "Enter the type of cannonball (iron, rock, or glass). \n";
	std::cin >> typeInput;
	std::cout << "Enter the value for the diameter of the cannonball (centimeters). \n";
	std::cin >> diameterInput;
	std::cout << "Enter the value for the height of the cannon (meters). \n";
	std::cin >> heightInput;
	std::cout << "Enter the value for the angle of the cannon. \n";
	std::cin >> angleInput;
	std::cout << "Enter the value for the initial speed of the cannonball (m/s). \n";
	std::cin >> velocityInput;
	std::cout << "Running the simulation...\n";

	Simulation simulation = Simulation(gravityInput, heightInput, diameterInput, angleInput, velocityInput, typeInput);
	double time = simulation.getTimeTakenToLand();
	std::cout << "It took " << time << " seconds for the cannonball to strike the ground. \n";
	//simulation.calculateDragForce();
	simulation.calculateTerminalVelocity();
};