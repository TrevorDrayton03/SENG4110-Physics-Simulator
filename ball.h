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

const double GENERIC_DENSITY = 0.002;
const double GENERIC_INITIAL_VELOCITY = 80.0;
const double GENERIC_DIAMETER = 10.0;
const double GENERIC_DRAG_COEFFICIENT = 0.002;
const double DENSITY_OF_AIR = 1.2; // 1.2 kg/cubic meter for air at NTP
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
		double dragCoefficient;
		double frontalArea;
		double mass;
		double initialVelocity;

	public:
		Ball();
		Ball(double gravity);
		double getDensity();
		void setDensity();
		double getDiameter();
		void setDiameter();
		double getWeight();
		void calculateWeight(double density, double gravity);
		std::string getType();
		void setType();
		double calculateVolume();
		double getVolume();
		void setVolume(double volume);
		double getDragCoefficient();
		void setDragCoefficient();
		double calculateFrontalArea();
		double getFrontalArea();
		void setFrontalArea(double frontalArea);
		double getMass();
		void setMass(double mass);
		double calculateMass();
		void setInitialVelocity();
	};
	
}
#endif 