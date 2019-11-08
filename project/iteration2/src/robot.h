/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/sensor_proximity.h"
#include "src/sensor_distress.h"
#include "src/sensor_entity_type.h"
#include "src/arena_mobile_entity.h"
#include "src/event_collision.h"
#include "src/entity_type.h"
#include "src/event_distress_call.h"
#include "src/event_proximity.h"
#include "src/event_type_emit.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Robot : public ArenaMobileEntity {
 public:
  explicit Robot(const struct robot_params* const params);

  void Reset(void);

  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }

  void TimestepUpdate(unsigned int dt);

/*
 * there are four Accep funciton, each one takes a type of event and pass to the apporpirat sensor
 * ther are a read event funciton to returan the type.
 */

/* the EventRecharge accept funciton */
  void Accept(EventRecharge * e);

/* the EventDistressCall accept funciton and its read*/
  void Accept(EventDistressCall * e);
  EventDistressCall * ReadEventDistressCall(void);

/* the EventCollision accept funciton and its read*/
  void Accept(EventCollision * e);
  EventCollision * ReadEventCollision(void);

/* the EventProximity accept funciton and its read*/
  void Accept(EventProximity * e);
  EventProximity * ReadEventProximity(void);

/* returen the rang of rhe rign proximity sensor */
  double RightProximitySensorRange(void) {right_sensor_proximity_.range();}

/* returen the rang of rhe left proximity sensor */
  double LeftProximitySensorRange(void) {left_sensor_proximity_.range();}

/* returen the rang of distress sensor */
  double DistressSensorRange(void) {sensor_distress_.range();}

/* check if the robot is movint around or frozen */
  void moving_around(bool ma) { moving_around_ = ma;}
  bool moving_around(void) {return moving_around_;}

  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }

  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }

  void sensor_touch(bool a) {sensor_touch_.sensed(a);}
  bool sensor_touch(void) {sensor_touch_.sensed();}

/* check if the robot is in distress situation or not */
  bool inDistress(void) {sensor_distress_.sensed();}

/*
* this funcitoin is to return the private enum variable
*/
  enum entity_type entityType(void) {return entity_type_;}

  int id(void) const { return id_; }
  std::string name(void) const {
    return "Robot" + std::to_string(id());}

 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  bool moving_around_ = true;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  SensorProximity right_sensor_proximity_;
  SensorProximity left_sensor_proximity_;
  SensorDistress sensor_distress_;
  enum entity_type entity_type_ = kRobot;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_H_
