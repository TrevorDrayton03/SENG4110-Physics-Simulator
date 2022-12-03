/**
* @brief Cannonball class definition file.
* @author Trevor Drayton
* @date 02/12/2022
* @version 1.0
*/

#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include "ball.h"

/**
* @brief Project library namespace.
*/
namespace projectlib
{
	/**
	* @brief Cannonball class used to determine the initial velocity of the simulation, determined by the type. Inherits the Ball class.
	* @see Ball::Ball()
	*/
	class Cannonball: public Ball {
	private:
	public:
		/**
		* Create a new Cannonball object.
		* @brief Default constructor.
		*/
		Cannonball();
		/**
		* Create a new Cannonball object from cannonball type. Called in the Simulation object.
		* @brief Constructor
		* @param type The cannonball type (rock, iron, or glass).
		* @see Simulation::Simulation(double gravity, double height, double angle, std::string type)
		*/
		Cannonball(std::string type);
		/**
		* @brief Set the type of the cannonball, if the type is not rock, glass, or iron, then the type is set to rock.
		* @param type The cannonball type.
		*/
		void setType(std::string type);
		/**
		* @brief Get the initial velocity of the cannonball.
		* @return Initial velocity.
		*/
		double getInitialVelocity();
		/**
		* @brief Set the initial velocity of the cannonball based on the cannonball's type.
		*/
		void setInitialVelocity();
	};
}
#endif 