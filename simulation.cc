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
		if (gravity == MIN_GRAVITY)
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
		else if (height == MIN_HEIGHT && angleInDegrees == MIN_ANGLE){
			timeToLand = 0.0;
		}
		else {
			timeToLand = (2.0*vy)/ gravity;
		}
		return timeToLand;
	}

	double Simulation::calculateDragForce() {
		double dragCoef = cannonball.getDragCoefficient();
		double frontalArea = cannonball.getFrontalArea();
		double initVel = getInitialVelocity();
		double dragForce = dragCoef*(0.5)*DENSITY_OF_AIR*(pow(initVel, 2)*frontalArea);
		std::cout << "dragForce " << dragForce << "\n";

		return dragForce;
	}
	double Simulation::calculateTerminalVelocity() {
		double dragCoef = cannonball.getDragCoefficient();
		double frontalArea = cannonball.getFrontalArea();
		double gravity = getGravity();
		double mass = cannonball.getMass();
		double terminalVelocity = sqrt((2.0*mass*gravity)/(DENSITY_OF_AIR*frontalArea*dragCoef));
		std::cout << "dragCoef " << dragCoef << "\n";
		std::cout << "diameter " << cannonball.getDiameter() << "\n";
		std::cout << "volume " << cannonball.getVolume() << "\n";
		std::cout << "density " << cannonball.getDensity() << "\n";
		std::cout << "frontalArea " << frontalArea << "\n";
		std::cout << "mass " << mass << "\n";
		std::cout << "terminalVelocity " << terminalVelocity << "\n";
		return terminalVelocity;
	}
	double Simulation::calculateAvgAcceleration() {
		double time = getTimeTakenToLand();
		double changeV = getInitialVelocity();
		double avgAccel = -1.0*changeV / time;
		std::cout << "avgAccel " << avgAccel << "\n";

		return avgAccel;
	}
	double Simulation::calculateXDistance() {
		double time = getTimeTakenToLand();
		double v = getInitialVelocity();
		double xDist = time * v;
		std::cout << "xDist " << xDist << "\n";
		return xDist;
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
	double Simulation::getInitialVelocity() {
		return this->initialVelocity;
	}
	void Simulation::setInitialVelocity(double initialVelocity) {
		this->initialVelocity = initialVelocity;
	}
}
