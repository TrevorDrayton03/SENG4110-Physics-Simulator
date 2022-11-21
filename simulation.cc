/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "simulation.h"

/**
* all units are SI
* diameter & height in cm
* density is kg/cubic cm
* volume is cubic cm
* force is in newtons = mass * (v/t)
*/
namespace projectlib
{
	Simulation::Simulation(double gravity, double height, double diameter, double angle, double initialVelocity, std::string type) {
		this->cannonball = Cannonball(gravity, diameter, type);
		this->cannon = Cannon(height, angle);
		setGravity(gravity);
		setinitialVelocity(initialVelocity);
		//setTime(0.0);
	}
	double Simulation::getTimeTakenToLand(Cannon cannon, Cannonball cannonball) {
		// v = g*t + vi -> want to know when v=0
		// 0 = 9.81t - vi*(sin(angle))
		// t = (2*vi*(sin(angle))) / 9.81 -> multiply by 2 cause we want the 2nd time v = 0 not t
		double t = (2 * getinitialVelocity() * sin(cannon.getAngle())) / getGravity();
		return t;
	}
	double Simulation::getHorizontalDistanceTravelled(Cannon cannon, Cannonball cannonball) {
		// x = (vi/2)t
		// vi = V*Cos(angle)
		double v = (this->initialVelocity) * cos(cannon.getAngle());
		double t = this->getTimeTakenToLand(cannon, cannonball);
		double x = (v / 2) * t;
		return x;
	}
	double Simulation::getVerticalDistanceTravelled() {
		// y = (vi)(t) + (1/2)(g)(t^2)
		// vi = V*Sin(angle)
		double v = (this->initialVelocity) * sin(this->cannon.getAngle());
		double t = this->getTimeTakenToLand(this->cannon, this->cannonball);
		double y = (v * t) + (1 / 2) * (getGravity()) * pow(t, 2);
		return y;
	}


	double Simulation::getGravity() {
		return this->gravity;
	}
	void Simulation::setGravity(double gravity) {
		this->gravity = gravity;
	}
	double Simulation::getinitialVelocity() {
		return this->initialVelocity;
	}
	void Simulation::setinitialVelocity(double initialVelocity) {
		this->initialVelocity = initialVelocity;
	}
	//double Simulation::getTime() {
	//	return this->time;
	//}
	//void Simulation::setTime(double time) {
	//	this->time = time;
	//}
}
