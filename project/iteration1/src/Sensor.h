/**
 * @file Sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/common.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

/**
 * @brief A representation of a sensor. it is the parent calss of all sensors
 * of all mobile entities
 *
 */
class Sensor {
 public:
  Sensor();

  /**
   * @brief Get the current activation reading from the sensor.
   */
  virtual bool activated(void) = 0;
  virtual void activated(bool value) = 0;

  virtual Position point_of_contact() = 0;
  virtual void point_of_contact(Position p) = 0;

  virtual double angle_of_contact(void) = 0;
  virtual void angle_of_contact(double aoc) = 0;

  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can report "no collision" which
   * will inactivate the sensor.
   *
   */

  virtual void Accept(EventCollision * e) = 0;

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  virtual void Reset(void) = 0;

 private:
  bool activated_;
  Position point_of_contact_;
  double angle_of_contact_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_SENSOR_H_
