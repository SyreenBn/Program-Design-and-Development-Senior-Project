/**
 * @file home_base_motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_HOME_BASE_MOTION_HANDLER_H_
#define SRC_HOME_BASE_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/home_base_params.h"
#include "src/arena_mobile_entity.h"
#include "src/home_base_sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The handler for the home base's actuators, which in this case are the
 * two wheel actuators.
 *
 * HomeBaseMotionHandler manages the modification to the velocity based on
 * collisions.
 * HomeBaseMotionHandler translates velocity and position to a new position.
 * Both of these are straightforward, but the framework allows for more
 * sophisticated models of motion in which each wheel has distinct speed.
 *
 * For this iteration, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class HomeBaseMotionHandler {
 public:
  HomeBaseMotionHandler();
  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   */
  void Reset(void) {
     heading_angle_ = 30;
     speed_ = 7;
  }
   /**
   * @brief Change the speed and direction according to the sensor readings.
   *
   * @param touch sensor that can be activated and contains point-of-contact.
   *
   */
  void UpdateVelocity(HomeBaseSensorTouch home_base_sensor_touch_);
  double speed() { return speed_; }
  void speed(double sp) {
    speed_ = sp; }
  double heading_angle() const { return heading_angle_;}
  void heading_angle(double ha) { heading_angle_ = ha; }
  double max_speed() { return max_speed_; }
  void max_speed(double ms) { max_speed_ = ms; }

 private:
  double heading_angle_;
  double speed_ = 5;
  double max_speed_;
  double change_angle = 0;
};
  /*! Namespaces End */
NAMESPACE_END(csci3081);
#endif  //  SRC_HOME_BASE_MOTION_HANDLER_H_
