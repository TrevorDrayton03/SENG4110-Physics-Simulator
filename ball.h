/**
* @brief Ball class definition file.
* @author Trevor Drayton
* @date 02/12/2022
* @version 1.0
*/

#ifndef BALL_H
#define BALL_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <cmath>

/**
* Constants within the ball's context are defined here.
*/
const double ROCK_INITIAL_VELOCITY = 100.0;
const double GLASS_INITIAL_VELOCITY = 120.0;
const double IRON_INITIAL_VELOCITY = 150.0;

/**
* @brief Project library namespace.
*/
namespace projectlib
{
	/**
	* @brief Ball class inherited by Cannonball.
	* @see Cannonball::Cannonball(std::string type)
	*/
	class Ball {
	protected: 
		/**
		* Type of ball (rock, iron, glass).
		*/
		std::string type;
		/**
		* Initial velocity of ball based on type.
		*/
		double initialVelocity;

	public:
		/**
		* Create a new Ball object.
		* @brief Default constructor.
		*/
		Ball();
		/**
		* @brief Get the type of the ball.
		* @return Type of ball (rock, iron, glass).
		*/
		std::string getType();
		/**
		* @brief Set the type of the ball to type "iron".
		*/
		void setType();
		/**
		* @brief Set the initial velocity to IRON_INITIAL_VELOCITY.
		* @see IRON_INITIAL_VELOCITY
		*/
		void setInitialVelocity();
	};
	
}
#endif 