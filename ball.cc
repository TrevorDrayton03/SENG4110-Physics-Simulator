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
		setDensity();
		setType();
		setDragCoefficient();
		calculateWeight(density, gravity);
	}
	double Ball::getDensity() {
		return this->density;
	}
	void Ball::setDensity() {
		this->density = GENERIC_DENSITY;
	}
	double Ball::getDiameter() {
		return this->diameter;
	}

	void Ball::setDiameter() {
		this->diameter = GENERIC_DIAMETER;
	}
	double Ball::getWeight() {
		return this->weight;
	}
	void Ball::calculateWeight(double density, double gravity) {
		this->weight = density * gravity;
	}
	std::string Ball::getType() {
		return this->type;
	}
	void Ball::setType() {
		this->type = GENERIC_TYPE;
	}
	double Ball::calculateVolume() {
		double vol = (1.0/6.0)*3.14*pow((this->diameter/100.0), 3); // divide by 100 to convert to meters
		return vol;
	}
	double Ball::getVolume() {
		return this->volume;
	}
	double Ball::getDragCoefficient() {
		return this->dragCoefficient;
	}
	void Ball::setDragCoefficient() {
		this->density = GENERIC_DRAG_COEFFICIENT;
	}
	double Ball::calculateFrontalArea() {
		// pir^2
		double fArea = 3.14*pow((this->diameter/2.0), 2);
		return fArea;
	}
	double Ball::getFrontalArea() {
		return this->frontalArea;
	}
	void Ball::setFrontalArea(double frontalArea) {
		this->frontalArea = frontalArea;
	}
	double Ball::getMass() {
		return this->mass;
	}
	void Ball::setMass(double mass) {
		this->mass = mass;
	}
	double Ball::calculateMass() {
		double massCalc = this->density * this->volume;
		return massCalc;
	}
	void Ball::setVolume(double volume) {
		this->volume = volume;
	}
}
