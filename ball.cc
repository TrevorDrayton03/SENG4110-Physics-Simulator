/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "ball.h"
//const double GENERIC_DENSITY = 0.002;
//const std::string GENERIC_TYPE = "generic";
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
	void Ball::calculateVolume(double diameter) {
		this->volume = (1 / 6) * 3.14 * pow(diameter, 3);
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

	}
}
