/**
* @brief
* @author Trevor Drayton
* @date
* @version 1.0
*/

#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

const double GENERIC_DENSITY = 0.002;
const std::string GENERIC_TYPE = "generic";

namespace projectlib
{
	class Ball {
	protected: 
		double density;
		double weight;
		std::string type;
		double volume;
		double diameter;

	public:
		Ball(double type, double gravity);
		double getDensity();
		void setDensity(double density);
		double getWeight();
		void calculateWeight(double density double gravity);
		std::string getType();
		void setType(std::string type);
		void calculateVolume(double diameter);

	};
	
}
#endif 