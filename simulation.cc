/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

namespace projectlib
{
	Simulation::Simulation(double gravity, double height, double diameter, double angle, std::string type) {
		this->cannonball = Cannonball(gravity, diameter, type);
		this->cannon = Cannon(height, angle);
		setGravity(gravity);
	}
	std::string Simulation::getType() {
		return cannonball.getType();
	}
	double Simulation::getTimeTakenToLand() {
		// t = (2*vi*(sin(angle)) + height[meters]) / gravity -> multiply by 2 cause we want the 2nd time v = 0
		double initVel = cannonball.getInitialVelocity();
		double angleInDegrees = cannon.getAngle() * RADIAN_TO_DEGREE_CONVERSION;
		double sinAngle = sin(angleInDegrees);
		double gravity = getGravity();
		double height = cannon.getHeight();
		double timeToLand = (((2 * initVel) * (sinAngle) + height) / gravity);
		return timeToLand;
	}

	double Simulation::calculateDragForce() {
		// Fd = Cd(1/2)p(v^2)A
		double dragCoef = cannonball.getDragCoefficient();
		double frontalArea = cannonball.getFrontalArea();
		double initVel = getInitialVelocity();
		double dragForce = dragCoef*(0.5)*DENSITY_OF_AIR*(pow(initVel, 2)*frontalArea);
		std::cout << "dragForce " << dragForce << "\n";

		return dragForce;
	}
	double Simulation::calculateTerminalVelocity() {
		// Vt = sqrt(2mg/pACd)
		double dragCoef = cannonball.getDragCoefficient();
		double frontalArea = cannonball.getFrontalArea();
		double gravity = getGravity();
		double mass = cannonball.getMass();
		double terminalVelocity = sqrt((2*mass*gravity)/(DENSITY_OF_AIR*frontalArea*dragCoef));
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
		// a = change V / change T
		double time = getTimeTakenToLand();
		double changeV = getInitialVelocity();
		double avgAccel = -1*changeV / time;
		std::cout << "avgAccel " << avgAccel << "\n";

		return avgAccel;
	}
	double Simulation::calculateXDistance() {
		// a = change V / change T
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
		this->gravity = gravity;
	}
	double Simulation::getInitialVelocity() {
		return this->initialVelocity;
	}
	void Simulation::setInitialVelocity(double initialVelocity) {
		this->initialVelocity = initialVelocity;
	}
}
