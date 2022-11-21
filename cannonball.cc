/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/

#include "cannonball.h"

//const double ROCK_DENSITY = 0.00168;
//const double GLASS_DENSITY = 0.0025;
//const double IRON_DENSITY = 0.0078;

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
	}
	void Cannonball::setType(std::string type) {
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
	Cannonball::Cannonball() {};
	Cannonball::Cannonball(double gravity, double diameter, std::string type) {
		setType(type);
		setDensity();
		calculateVolume(diameter);
		calculateWeight(getDensity(), gravity);
	}
}
