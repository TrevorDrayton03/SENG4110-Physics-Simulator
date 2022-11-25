/**
* @brief
* @author Trevor Drayton
* @date
* @version 1.0
*/

#ifndef SIMULATION_H
#define SIMULATION_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "cannon.h"
#include "cannonball.h"
#include <cmath>

const double RADIAN_TO_DEGREE_CONVERSION = (3.14 / 180.0);
const double MIN_MINUS_GRAVITY = -1.0;
const double MIN_MINUS_ANGLE = -1.0;
const double MIN_MINUS_HEIGHT = -1.0;

const double MIN_GRAVITY = 0.0;
const double MIN_ANGLE = 0.0;
const double MIN_HEIGHT = 0.0;

const double MIN_PLUS_GRAVITY = 1.0;
const double MIN_PLUS_ANGLE = 1.0;
const double MIN_PLUS_HEIGHT = 1.0;

const double MAX_MINUS_GRAVITY = 99;
const double MAX_MINUS_ANGLE = 89.0;
const double MAX_MINUS_HEIGHT = 99.0;

const double MAX_GRAVITY = 100.0;
const double MAX_ANGLE = 90.0;
const double MAX_HEIGHT = 100.0;

const double MAX_PLUS_GRAVITY = 101.0;
const double MAX_PLUS_ANGLE = 91.0;
const double MAX_PLUS_HEIGHT = 101.0;

const double NOMINAL_GRAVITY = 9.8;
const double NOMINAL_ANGLE = 45.0;
const double NOMINAL_HEIGHT = 5.0;
namespace projectlib
{
	class Simulation {
	private: 
		Cannonball cannonball;
		Cannon cannon;
		double gravity;
	public:
		Simulation(double gravity, double height, double angle, std::string type);
		Simulation();
		double getGravity();
		void setGravity(double gravity);
		std::string getType();
		double getTimeTakenToLand();
	};
	
}
#endif 