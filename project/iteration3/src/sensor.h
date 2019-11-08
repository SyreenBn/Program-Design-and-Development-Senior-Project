/**
 * @file sensor.h
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
#include "src/arena_entity.h"
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Classes
 ******************************************************************************/

/**
 * @brief A representation of a sensor. it is the parent calss of all sensors
 * of all mobile entities
 */
class Sensor {
 public:
Sensor();

  /**
   * @brief Get the current activation reading from the sensor.
   */
bool sensed(void) {return sensed_;}
void sensed(bool value) {sensed_ = value;}

/**
 * @brief Compute a new reading based on the collision event.
 *
 * Note that collision events can report "no collision" which
 * will inactivate the sensor.
 *
 */
void Accept(const EventBaseClass * e);
virtual EventBaseClass * read(void) {return event_;}
void Accept(EventBaseClass * e);

  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can report "no collision" which
   * will inactivate the sensor.
   *
   */

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
void Reset(void) {sensed_ = false;}

/*
 * @brief this fuction is to set and get the range of the sensor
 */
double get_range() { return range_;}

 private:
  EventBaseClass * event_;
  const ArenaEntity * entity_;
  float range_;
  bool sensed_;
  double field_of_view_ang;
  Position point_of_contact_;
  double angle_of_contact_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_SENSOR_H_
