/**
* @brief Ball class declaration file.
* @author Trevor Drayton
* @date 02/12/2022
* @version 1.0
*/

#include "ball.h"

namespace projectlib
{
	Ball::Ball() {
		setType();
		setInitialVelocity();
	}
	void Ball::setInitialVelocity() {
		this->initialVelocity = IRON_INITIAL_VELOCITY;
	}
	std::string Ball::getType() {
		return this->type;
	}
	void Ball::setType() {
		this->type = "iron";
	}
}
