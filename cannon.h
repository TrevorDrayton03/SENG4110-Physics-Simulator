/**
* @brief
* @author Trevor Drayton
* @date
* @version 1.0
*/

#ifndef CANNON_H
#define CANNON_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

namespace projectlib
{
	class Cannon {
	private:
		double height;
		double angle;
	public:
		Cannon();
		Cannon(double height, double angle);
		double getAngle();
		void setAngle(double angle);
	};
}
#endif 