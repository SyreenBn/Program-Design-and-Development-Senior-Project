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
#include "src/sensor_proximity.h"
#include "src/sensor_distress.h"
#include "src/sensor_entity_type.h"
#include "src/arena_mobile_entity.h"
#include "src/event_collision.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/* I did not work to change the robot and make a super bot yer */
/*
 * @brief this class to create the super_bot which is found when the robot hit
 * home_base
 */
class SuperBot : public ArenaMobileEntity {
 public:
  explicit SuperBot(const struct super_bot_params* const params);

  void Reset(void);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  void TimestepUpdate(unsigned int dt);

  /* @brief to Accept EventCollision from the arena and pass it to the sensor */
  void Accept(EventCollision * e);

/* @brief to set and get the heading_angle of motion handler*/
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }

  /* @brief to set and get the speed of motion handler*/
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }


  /* returen the rang of rhe rign proximity sensor */
    double RightProximitySensorRange(void) {right_sensor_proximity_.range();}

    double RightProximitySensorAngle(void) {right_sensor_proximity_.field();}


  /* returen the rang of rhe left proximity sensor */
    double LeftProximitySensorRange(void) {left_sensor_proximity_.range();}

  /* returen the rang of distress sensor */
    double DistressSensorRange(void) {sensor_distress_.range();}

/* @brief it is return -1 when the event clall this function in arena*/
  int id(void) const { return id_; }

  /*
   * this funcitoin is to return the private enum varialbe
   */
//  enum entity_type entityType(void) {return entity_type_;}

/* @brief this funcito is to print the nameof hte Player
 *
 */
  std::string name(void) const {
    return "SuperBot" + std::to_string(id());}

    const int& get_id(void) const { return id__; }

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
  SensorEntityType sensor_entity_type_;
  int id__ = -1;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_SUPER_BOT_H_
