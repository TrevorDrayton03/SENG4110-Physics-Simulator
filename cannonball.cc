/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "cannonball.h"

namespace projectlib
{
	void Cannonball::setDensity() {
		if (this->type == "rock")
		{
			this->density = ROCK_DENSITY;
		}
		else if (this->type == "glass")
		{
			this->density = GLASS_DENSITY;
		}
		else if (this->type == "iron")
		{
			this->density = IRON_DENSITY;
		}
		else
		{
			this->density = GENERIC_DENSITY;
		}
	}
	void Cannonball::setType(std::string type) {
		if (!(type == "rock" || type == "glass" || type == "iron")) {
			this->type = GENERIC_TYPE;
		}
		else {
			this->type = type;
		}
	}
	void Cannonball::setDragCoefficient() {
		if (this->type == "rock")
		{
			this->dragCoefficient = ROCK_COEFFICIENT;
		}
		else if (this->type == "glass")
		{
			this->dragCoefficient = GLASS_COEFFICIENT;
		}
		else if (this->type == "iron")
		{
			this->dragCoefficient = IRON_COEFFICIENT;
		}
		else
		{
			this->dragCoefficient = GENERIC_DRAG_COEFFICIENT;
		}
	}
	double Cannonball::getDragCoefficient() {
		return this->dragCoefficient;
	}
	void Cannonball::setDiameter(double diameter) {
		this->diameter = diameter;
	}
	Cannonball::Cannonball() {};
	Cannonball::Cannonball(double gravity, double diameter, std::string type) {
		setType(type);
		setDiameter(diameter);
		setDensity();
		setDragCoefficient();
		setVolume(calculateVolume());
		setMass(calculateMass());
		setFrontalArea(calculateFrontalArea());
	}
}
