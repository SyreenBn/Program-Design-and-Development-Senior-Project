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
#include "src/sensor_touch.h"
#include "src/sensor_entity_type.h"
#include "src/entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /*
 * @brief this classe is to create the home base which change hte robot and make
 * SuperBot
 */
class HomeBase: public ArenaMobileEntity {
 public:
  explicit HomeBase(const struct home_base_params* const params);

/* @brief this functio is to reset the HomeBase to the original siutation */
  void Reset(void);

  /* @brief to set and get the heading_angle */
  double heading_angle(void) const {
    return home_base_motion_handler_.heading_angle(); }
  void heading_angle(double ha) { home_base_motion_handler_.heading_angle(ha); }

  /* @brief to set and get the speed */
  double speed(void) { return home_base_motion_handler_.speed(); }
  void speed(double sp) { home_base_motion_handler_.speed(sp); }

  /* @brief to Accept EventCollision from the arena and pass it to the sensor */
  void Accept(EventCollision * e);

  /* @brief this funciton does not use but I need ot create it because it is
   * virtual in the arena enitity calss
   */
  void Accept(EventRecharge * e);

  void TimestepUpdate(uint dt);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }

  /* @brief this funcito is to print the nameof hte HomeBase
   *
   */
  std::string name(void) const { return "HomeBase"; }

/* @brief it is return -1 when the event clall this function in arena*/
  const int& get_id(void) const { return id_; }

  /* @brief it is return the char of the enitity type to use it in the robot
   * when checking the senarios of collision
   */
  const char& entity_type(void)const {return entity_type_;}

 private:
  HomeBaseMotionHandler home_base_motion_handler_;
  HomeBaseMotionBehavior motion_behavior_;
  double heading_angle_;
  double angle_delta_;
  SensorTouch home_base_sensor_touch_;
  int id_ = -1;
  char entity_type_ = 'h';
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
