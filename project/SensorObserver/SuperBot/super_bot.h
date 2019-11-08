/**
 * @file super_bot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SUPER_BOT_H_
#define SRC_SUPER_BOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/super_bot_motion_handler.h"
#include "src/super_bot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "sensor_proximity.h"
#include "sensor_distress.h"
#include "sensor_entity_type.h"
#include "src/arena_mobile_entity.h"
#include "src/event_collision.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class SuperBot : public ArenaMobileEntity {
 public:
  explicit SuperBot(const struct super_bot_params* const params);

  void Reset(void);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  void TimestepUpdate(unsigned int dt);
  void Accept(EventCollision * e);
  void Accept(EventRecharge * e);
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }
  int id(void) const { return id_; }
  std::string name(void) const {
    return "SuperBot" + std::to_string(id());}

 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  SuperBotMotionHandler motion_handler_;
  SuperBotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  SensorProximity right_sensor_proximity_;
  SensorProximity left_sensor_proximity_;
  SensorDistress sensor_distress_;
//  SensorEntityType sensor_entity_type_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_SUPER_BOT_H_
