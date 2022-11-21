/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "cannon.h"

namespace projectlib
{
	Cannon::Cannon() {};
	Cannon::Cannon(double height, double angle) {
		this->height = height;
		this->setAngle(angle);
	}

	double Cannon::getAngle() {
		return this->angle;
	}
	void Cannon::setAngle(double angle) {
		this->angle = angle;
	}
}
