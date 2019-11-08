/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include "src/sensor.h"
#include "src/common.h"
#include "src/event_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

class SensorProximity : public Sensor {
 public:
SensorProximity();
~SensorProximity() {}
  /**
   * @brief Get the current activation reading from the sensor.
   */

  /*
   * this funciton is the to tell the user if the sensor is on or off, check if it is activiaed or not
   */
  bool sensed(void) { return sensed_; }
  void sensed(bool value) { sensed_ = value; }
  /*
   * this fuction is to return a number value of the activated situaiton
   */
  int output() {
    if (sensed_) { return -1;
    } else {return 0;}}

  /*
   * this fuction is to set and get the range of the sensor
   */

  float range(void) { return range_; }
  void range(float ran) { range_ = ran; }

  /*
   * this fuction is to the field of viwe of the sensor
   */
  float field(void) { return field_; }
  void field(float fld) { field_ = fld; }

  /*
   * this fuction is to the position of contact of the sensor
   */

  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) {
    point_of_contact_.x = p.x;
    point_of_contact_.y = p.y;
  }

  /*
   * this fuction is to the angle of contact of the sensor
   */


  double angle_of_contact(void) { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }
  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can report "no collision" which
   * will inactivate the sensor.
   *
   */

  void Accept(EventProximity * e);

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */

  void Reset(void);

 private:
  bool sensed_;
  float range_;
  float field_;
  Position point_of_contact_;
  double angle_of_contact_;
};

NAMESPACE_END(csci3081);

#endif   // SRC_SENSOR_PROXIMITY_H_
