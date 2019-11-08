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
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class HomeBase: public ArenaMobileEntity {
 public:
  explicit HomeBase(const struct home_base_params* const params);

  void Reset(void);
  double heading_angle(void) const {
    return home_base_motion_handler_.heading_angle(); }
  void heading_angle(double ha) { home_base_motion_handler_.heading_angle(ha); }
  double speed(void) { return home_base_motion_handler_.speed(); }
  void speed(double sp) { home_base_motion_handler_.speed(sp); }
  void Accept(EventCollision * e);
  void Accept(EventRecharge * e);
  void TimestepUpdate(uint dt);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  std::string name(void) const { return "HomeBase"; }
//  enum entity_type entityType(void) {return entity_type_;}
  const int& get_id(void) const { return id_; }
  const char& entity_type(void)const {return entity_type_;}


 private:
  HomeBaseMotionHandler home_base_motion_handler_;
  HomeBaseMotionBehavior motion_behavior_;
  double heading_angle_;
  double angle_delta_;
  SensorTouch home_base_sensor_touch_;
  //enum entity_type entity_type_ = kHomeBase;
  int id_ = -1;
  char entity_type_ = 'h';

};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_HOME_BASE_H_
