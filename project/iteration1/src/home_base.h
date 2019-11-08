/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */
#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/arena_mobile_entity.h"
#include "src/home_base_motion_handler.h"
#include "src/home_base_motion_behavior.h"
#include "src/event_collision.h"
#include "src/home_base_sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class HomeBase: public ArenaMobileEntity {
 public:
  explicit HomeBase(const struct home_base_params* const params);

  void Reset(void);
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }
  void Accept(EventCollision * e);
  void Accept(EventRecharge * e);
  void TimestepUpdate(uint dt);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  std::string name(void) const { return "Home Base"; }

 private:
  HomeBaseMotionHandler motion_handler_;
  HomeBaseMotionBehavior motion_behavior_;
  double heading_angle_;
  double angle_delta_;
  HomeBaseSensorTouch home_base_sensor_touch_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
