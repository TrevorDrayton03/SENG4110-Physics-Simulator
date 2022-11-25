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

namespace projectlib
{
	class Cannonball: public Ball {
	private:
	public:
		Cannonball();
		Cannonball(double gravity, std::string type);
		void setType(std::string type);
		double getInitialVelocity();
		void setInitialVelocity();
	};
}
#endif 