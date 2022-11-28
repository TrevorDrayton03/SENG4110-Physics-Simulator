/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "cannonball.h"

/**
* @namespace projectlib
*/
namespace projectlib
{
	void Cannonball::setInitialVelocity() {
		if (this->type == "rock")
		{
			this->initialVelocity = ROCK_INITIAL_VELOCITY;
		}
		else if (this->type == "glass")
		{
			this->initialVelocity = GLASS_INITIAL_VELOCITY;
		}
		else
		{
			this->initialVelocity = IRON_INITIAL_VELOCITY;
		}
	}
	void Cannonball::setType(std::string type) {
		if (!(type == "rock" || type == "glass" || type == "iron")) {
			this->type = "rock";
		}
		else {
			this->type = type;
		}
	}
	double Cannonball::getInitialVelocity() {
		return this->initialVelocity;
	}
	Cannonball::Cannonball() {};
	Cannonball::Cannonball(double gravity, std::string type) {
		setType(type);
		setInitialVelocity();
	}
}
