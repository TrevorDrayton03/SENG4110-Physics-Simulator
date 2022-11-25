/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "ball.h"

namespace projectlib
{
	Ball::Ball() {};
	Ball::Ball(double gravity) {
		setType();
		setInitialVelocity();
	}
	void Ball::setInitialVelocity() {
		this->density = IRON_INITIAL_VELOCITY;
	}
	std::string Ball::getType() {
		return this->type;
	}
	void Ball::setType() {
		this->type = "iron";
	}
}
