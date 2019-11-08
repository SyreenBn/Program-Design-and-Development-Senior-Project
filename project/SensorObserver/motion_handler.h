/**
 * @file actuator motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_MOTION_HANDLER_H_
#define SRC_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
//#include "src/robot_params.h"
#include "src/arena_mobile_entity.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

class MotionHandler {
 public:
  MotionHandler();
  virtual void Reset(void) = 0;
  virtual void UpdateVelocity(SensorTouch st) = 0 ;

  virtual double speed() ;
  virtual void speed(double sp) ;

  virtual double heading_angle() const ;
  virtual void heading_angle(double ha) ;

  virtual double max_speed() ;
  virtual void max_speed(double ms) ;

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_ROBOT_MOTION_HANDLER_H_
