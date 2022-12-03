/**
* @brief Cannon class definition file.
* @author Trevor Drayton
* @date 02/12/2022
* @version 1.0
*/

#ifndef CANNON_H
#define CANNON_H

#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>

/**
* @brief Project library namespace.
*/
namespace projectlib
{
	/**
	* @brief Cannon class used to encapsulate the height and angle of the simulation.
	*/
	class Cannon {
	private:
		/**
		* Distance of cannon from the ground in meters.
		*/
		double height;
		/**
		* Angle of the cannon above the ground in degrees.
		*/
		double angle;
	public:
		/**
		* Create a new Cannon object.
		* @brief Default constructor.
		*/
		Cannon();
		/**
		* Create a new Cannon object with height and angle values.
		* @brief Default constructor.
		* @param height Distance of cannon from the ground in meters.
		* @param angle Angle of the cannon above the ground in degrees.
		*/
		Cannon(double height, double angle);
		/**
		* @brief Set the angle of the cannonball.
		* @return Angle of the cannon above the ground in degrees.
		*/
		double getAngle();
		/**
		* @brief Set the angle of the cannonball.
		* @param angle Angle of the cannon above the ground in degrees.
		*/
		void setAngle(double angle);
		/**
		* @brief Get the height of the cannonball.
		* @return Distance of cannon from the ground in meters.
		*/
		double getHeight();
		/**
		* @brief Set the height of the cannonball.
		* @param height Distance of cannon from the ground in meters.
		*/
		void setHeight(double height);
	};
}
#endif 