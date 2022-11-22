/**
* @brief
* @author Trevor Drayton
* @date
* @version 1.0
*/

#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "ball.h"

const double ROCK_DENSITY = 0.00168;
const double GLASS_DENSITY = 0.0025;
const double IRON_DENSITY = 0.0078;
const double ROCK_COEFFICIENT = 0.4;
const double GLASS_COEFFICIENT = 0.5;
const double IRON_COEFFICIENT = 0.45;
const double ROCK_INITIAL_VELOCITY = 100.0;
const double GLASS_INITIAL_VELOCITY = 120.0;
const double IRON_INITIAL_VELOCITY = 150.0;

namespace projectlib
{
	class Cannonball: public Ball {
	private:
	public:
		Cannonball();
		Cannonball(double gravity, double diameter, std::string type);
		void setDensity();
		void setType(std::string type);
		void setDragCoefficient();
		double getDragCoefficient();
		void setDiameter(double diameter);
		double getInitialVelocity();
		void setInitialVelocity();
	};
}
#endif 