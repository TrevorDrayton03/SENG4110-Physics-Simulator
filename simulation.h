/**
* @brief
* @author Trevor Drayton
* @date
* @version 1.0
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "cannon.h"
#include "cannonball.h"
#include <cmath>
const double RADIAN_TO_DEGREE_CONVERSION = (3.14 / 180.0);
namespace projectlib
{
	class Simulation {
	private: 
		Cannonball cannonball;
		Cannon cannon;
		double gravity;
		double initialVelocity;
		double time;
	public:
		Simulation(double gravity, double height, double diameter, double angle, double initialVelocity, std::string type);
		double getGravity();
		void setGravity(double gravity);
		double getInitialVelocity();
		void setInitialVelocity(double initialVelocity);
		double getTime();
		void setTime(double time);
		double getTimeTakenToLand();
		double getVerticalDistanceTravelled();
		double getHorizontalDistanceTravelled(Cannon cannon, Cannonball cannonball);
	};
	
}
#endif 