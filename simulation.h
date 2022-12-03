/**
* @brief Simulation class definition file.
* @author Trevor Drayton
* @date 02/12/2022
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

/**
* Constants within the simulation's context are defined here.
*/
const double DEGREE_TO_RADIAN_CONVERSION = (3.14 / 180.0);
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

/**
* @brief Project library namespace.
*/
namespace projectlib
{
	/**
	* @brief Simulation class used to encapsulate the physics simulation. Composed of a Cannonball, Cannon, and a gravity attribute.
	*/
	class Simulation {
	private: 
		/**
		* Instantiate the Cannonball object.
		*/
		Cannonball cannonball;
		/**
		* Instantiate the Cannon object.
		*/
		Cannon cannon;
		/**
		* Contain the gravity value.
		*/
		double gravity;
	public:
		/**
		* Create a new Simulation object from gravity, cannon height, cannon angle, and cannonball type.
		* A Cannon and Cannonball object are encapsulated and constructed inside the simulation.
		* @brief Constructor
		* @param gravity The gravity value in the simulation.
		* @param height The height value of the cannon above the ground in meters.
		* @param angle The angle value of the cannon above the ground in degrees.
		* @param type The cannonball type (rock, iron, or glass).
		* @see Cannon::Cannon(double height, double angle)
		* @see Cannonball::Cannonball(std::string type)
		*/
		Simulation(double gravity, double height, double angle, std::string type);
		/**
		* Create a new Simulation object.
		* @brief Default Constructor
		*/
		Simulation();
		/**
		* @brief Get the gravity of the simulation.
		* @return The value of gravity in Newtons.
		*/
		double getGravity();
		/**
		* @brief Set the value of the gravity of the simulation. If the gravity is less than zero, it's set to 1.0.
		* @param gravity The value of gravity in Newtons.
		*/
		void setGravity(double gravity);
		/**
		* @brief Get the type of cannonball.
		* @return The type of cannonball in a string.
		*/
		std::string getType();
		/**
		* @brief Get the time taken for the cannonball to land after being launched from the cannon.
		* @return The time taken to land in the form of a double.
		*/
		double getTimeTakenToLand();
		/**
		* @brief Creates a simulation object for the slice tests to use.
		* @return Simulation object with gravity = 9.8, type = "iron", angle = 30.0, and height = 0.
		*/
		Simulation Pre_Slice();
		/**
		* @brief Slice test for line 22 of the simulation.cc file.
		* @return The angle in degrees.
		*/
		double Slice22(Simulation simulation);
		/**
		* @brief Slice test for line 23 of the simulation.cc file.
		* @return The angle of the cannon in degrees.
		*/
		double Slice23(Simulation simulation);
		/**
		* @brief Slice test for line 24 of the simulation.cc file.
		* @return The velocity of the ball in the y-direction only.
		*/
		double Slice24(Simulation simulation);
		/**
		* @brief Slice test for line 25 of the simulation.cc file.
		* @return The height of the cannon in meters.
		*/
		double Slice25(Simulation simulation);
		/**
		* @brief Instantiate the timeToLand variable.
		* @return timeToLand.
		*/
		double Slice26();
		/**
		* @brief Slice test for line 27 of the simulation.cc file.
		* @return timeToLand = 0.0.
		*/
		double Slice27(double gravity, double height, double angleInDegrees);
		/**
		* @brief Slice test for line 32 of the simulation.cc file.
		* @return height.
		*/
		double Slice32(double height);
		/**
		* @brief Slice test for line 35 of the simulation.cc file.
		* @return angle.
		*/
		double Slice35(double angleInDegrees);
		/**
		* @brief Slice test for line 38 of the simulation.cc file.
		* @return gravity.
		*/
		double Slice38(double gravity);
		/**
		* @brief Slice test for line 41 of the simulation.cc file.
		* @return timeToLand.
		*/
		double Slice41(double height, double gravity, double vy);
		/**
		* @brief Slice test for line 45 of the simulation.cc file.
		* @return timeToLand.
		*/
		double Slice45(double vy, double gravity);
	};
	
}
#endif 