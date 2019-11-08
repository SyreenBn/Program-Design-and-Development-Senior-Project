/**
 * @file actuator motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_H_
#define SRC_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/*@breif
* this is a abstract class for all motion handler of all other enities
*/

/**
 * @brief The handler for the entity actuators, which in this case are the two
 * wheel actuators. Its main job is to translate the directional commands from
 * the user into the appropriate differential drive wheel speeds.
 *
 * MotionHandler manages the modification to the velocity based on
 * user input and collisions.
 * MotionBehavior translates velocity and position to a new position.
 * Both of these are straightforward, but the framework allows for more
 * sophisticated models of motion in which each wheel has distinct speed.
 *
 * For this iteration, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */


class MotionHandler {
 public:
  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   */

  virtual void Reset(void) = 0;

/**
  * @brief Change the speed and direction according to the sensor readings.
  *
  * @param touch sensor that can be activated and contains point-of-contact.
  *
  */
  //virtual void UpdateVelocity(SensorTouch st) = 0;

/* this is the set and get funciton of the speed */
  virtual double speed() = 0;
  virtual void speed(double sp) = 0;

/* this is the set and get funciton of the heading angle */
  virtual double heading_angle() const = 0;
  virtual void heading_angle(double ha) = 0;

/* this is the set and get funciton of max speed */
  virtual double max_speed() = 0;
  virtual void max_speed(double ms) = 0;
};
/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_MOTION_HANDLER_H_
