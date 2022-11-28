/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

/**
* @namespace projectlib
*/
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
		double angleInDegrees = cannon.getAngle() * DEGREE_TO_RADIAN_CONVERSION;
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
	Simulation Simulation::Pre_Slice() {
		std::string typeInput = "iron";
		double angleInput = 30.0;
		double heightInput = 0;
		double gravityInput = 9.8;
		Simulation simulation = Simulation(gravityInput, heightInput, angleInput, typeInput);
		return simulation;
	}
	double Simulation::Slice22(Simulation simulation) {
		double angleInDegrees = simulation.cannon.getAngle() * DEGREE_TO_RADIAN_CONVERSION;
		return angleInDegrees;
	}
	double Simulation::Slice23(Simulation simulation) {
		double angleInDegrees = Slice22(simulation);
		double vy = sin(angleInDegrees) * simulation.cannonball.getInitialVelocity();
		return vy;
	}
	double Simulation::Slice24(Simulation simulation) {
		double gravity = simulation.getGravity();
		return gravity;
	}
	double Simulation::Slice25(Simulation simulation) {
		double height = simulation.cannon.getHeight();
		return height;
	}
	double Simulation::Slice26() {
		double timeToLand = 0;
		return timeToLand;
	}
	double Simulation::Slice27(double gravity, double height, double angleInDegrees) {
		double timeToLand;
		if (gravity == MIN_GRAVITY || (height == MIN_HEIGHT && angleInDegrees == MIN_ANGLE))
		{
			timeToLand = 0.0;
			return timeToLand;
		}
	}
	double Simulation::Slice32(double height) {
		if (height < MIN_HEIGHT || height > MAX_HEIGHT) {
			height = NOMINAL_HEIGHT;
		}
		return height;
	}
	double Simulation::Slice35(double angleInDegrees) {
		if (angleInDegrees < MIN_ANGLE || angleInDegrees > MAX_ANGLE) {
			angleInDegrees = NOMINAL_ANGLE;
		}
		return angleInDegrees;
	}
	double Simulation::Slice38(double gravity) {
		if (gravity < MIN_GRAVITY || gravity > MAX_GRAVITY) {
			gravity = NOMINAL_GRAVITY;
		}
		return gravity;
	}
	double Simulation::Slice41(double height, double gravity, double vy) {
		double timeToLand;
		if (height > MIN_HEIGHT)
		{
			timeToLand = (vy + sqrt((pow(vy, 2.0) + 2.0 * gravity * height))) / gravity;
		}
		return timeToLand;
	}
	double Simulation::Slice45(double vy, double gravity) {
		double timeToLand = (2.0 * vy) / gravity;
		return timeToLand;
	}

}
