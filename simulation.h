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
		Simulation(double gravity, double height, double diameter, double angle, std::string type);
		double getGravity();
		void setGravity(double gravity);
		double getinitialVelocity();
		void setinitialVelocity(double initialVelocity);
		double getTime();
		void setTime(double time);
		double getTimeTakenToLand(Cannon cannon, Cannonball cannonball);
		double getVerticalDistanceTravelled(Cannon cannon, Cannonball cannonball);
		double getHorizontalDistanceTravelled(Cannon cannon, Cannonball cannonball);
	};
	
}
#endif 