/**
* @brief Main function of the simple physics simulator. Gets the time taken for a cannonball to land.
* @author Trevor Drayton
* @date 02/12/2022
* @version 1.0
*/

#include "simulation.h"

using namespace projectlib;
int main(int argc, char **argv)
{
	double gravityInput, heightInput, angleInput;
	std::string typeInput;
	if (argc != 5) {
		std::cerr << "Wrong number of arguments." << std::endl;
		return 1;
	}
	else {
		gravityInput = std::atof(argv[1]);
		typeInput = std::string(argv[2]);
		angleInput = std::atof(argv[3]);
		heightInput = std::atof(argv[4]);
	}

	Simulation simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
	double time = simulation.getTimeTakenToLand();
	std::cout << "It took " << time << " seconds for the " <<simulation.getType()<<" cannonball to strike the ground. \n";
};