/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

namespace projectlib
{
	Simulation::Simulation(double gravity, double height, double angle, std::string type) {
		this->cannonball = Cannonball(gravity, type);
		this->cannon = Cannon(height, angle);
		setGravity(gravity);
	}
	Simulation::Simulation() {};
	std::string Simulation::getType() {
		return cannonball.getType();
	}
	double Simulation::getTimeTakenToLand() {
		double angleInDegrees = cannon.getAngle() * RADIAN_TO_DEGREE_CONVERSION;
		double vy = sin(angleInDegrees) * cannonball.getInitialVelocity();
		double gravity = getGravity();
		double height = cannon.getHeight();
		double timeToLand;
		if (gravity == MIN_GRAVITY || (height == MIN_HEIGHT && angleInDegrees == MIN_ANGLE))
		{
			timeToLand = 0.0;
			return timeToLand;
		}
		if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
			height = NOMINAL_HEIGHT;
		}
		if (angleInDegrees < MIN_ANGLE || angleInDegrees > MAX_ANGLE) {
			angleInDegrees = NOMINAL_ANGLE;
		}
		if (gravity < MIN_GRAVITY || gravity > MAX_GRAVITY) {
			gravity = NOMINAL_GRAVITY;
		}
		if (height > MIN_HEIGHT)
		{
			timeToLand = (vy + sqrt((pow(vy, 2.0) + 2.0 * gravity * height))) / gravity;
		}
		else {
			timeToLand = (2.0*vy)/ gravity;
		}
		return timeToLand;
	}

	double Simulation::getGravity() {
		return this->gravity;
	}
	void Simulation::setGravity(double gravity) {
		if (gravity >= 0.0) {
			this->gravity = gravity;
		}
		else
		{
			this->gravity = 1.0;
		}
	}
}
