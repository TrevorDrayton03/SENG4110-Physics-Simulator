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

namespace projectlib
{
	class Cannonball: public Ball {
	private:
	public:
		Cannonball();
		Cannonball(double gravity, double diameter, std::string type);
		void setDensity();
		void setType(std::string type);
	};
}
#endif 