/**
 * @file sensor_distress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_DISTRESS_H_
#define SRC_SENSOR_DISTRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include "src/sensor.h"
#include "src/common.h"
#include "src/event_distress_call.h"
#include "src/arena_entity.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

/**
 * @brief A representation of a disstress call. recive the sign for the other robot
 * sensors are "active" when pressed. For our purposes,
  * around the perimeter of the robot. A disstress will activate the sensor
  * at a particular point of contact, which translates to an angle of contact
  */
class SensorDistress  : public Sensor {
 public:
  SensorDistress();
  ~SensorDistress() {}

  /*
   * @brief this funciton is the to tell the user if the sensor
   * is on or off, check if it is activiaed or not
   */
  bool sensed(void) { return sensed_; }
  void sensed(bool value) { sensed_ = value; }

  /*
   * @brief this fuction is to set and get the range of the sensor
   */
  float range(void) { return range_; }
  void range(float ran) { range_ = ran; }

  /*
   * @brief this fuction is to the position of contact of the sensor
   */
  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) {
    point_of_contact_.x = p.x;
    point_of_contact_.y = p.y;
  }

  /*
   * @brief this fuction is to the angle of contact of the sensor
   */
  double angle_of_contact(void) { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

  /**
   * @brief Compute a new reading based on the DistressCall event.
   *
   * Note that DistressCall events can report "no DistressCall" which
   * will inactivate the sensor.
   *
   */
  void Accept(EventDistressCall * ed);
  void Accept(EventBaseClass * ed);
  EventDistressCall * get_reading(void);

  /*
   * @brief this funciton is the to tell the user if the sensor
   * is on or off, check if it is activiaed or not but it return a num output
   */
  int output() {
    if (sensed_) {return 1;
    } else {return 0;} }

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  void Reset();

 private:
  Position point_of_contact_;
  double angle_of_contact_;
  double range_;
  bool sensed_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);
#endif  //  SRC_SENSOR_DISTRESS_H_
