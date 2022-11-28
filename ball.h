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
#include <cmath>

const double ROCK_INITIAL_VELOCITY = 100.0;
const double GLASS_INITIAL_VELOCITY = 120.0;
const double IRON_INITIAL_VELOCITY = 150.0;

/**
* @namespace projectlib
*/
namespace projectlib
{
	class Ball {
	protected: 
		double density;
		double weight;
		std::string type;
		double volume;
		double diameter;
		double dragCoefficient;
		double frontalArea;
		double mass;
		double initialVelocity;

	public:
		Ball();
		Ball(double gravity);
		std::string getType();
		void setType();
		void setInitialVelocity();
	};
	
}
#endif 