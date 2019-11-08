/**
 * @file home_base_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/home_base_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
HomeBaseMotionHandler::HomeBaseMotionHandler():
  heading_angle_(0),
  speed_(7),
  max_speed_(10) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/* this class is implemented as the robot motion handler
 * except the AcceptCommand fun
 */
void HomeBaseMotionHandler::UpdateVelocity(
                                  HomeBaseSensorTouch home_base_sensor_touch_) {
/*
 * This if statment to change the angle by adding 90 degree to the
 * angle of contact every 10 calls of UpdateVelocity
 */
if (change_angle < 10) {
    heading_angle_ = - home_base_sensor_touch_.angle_of_contact();
    change_angle++;
} else {
    heading_angle_ = - home_base_sensor_touch_.angle_of_contact();
    home_base_sensor_touch_.angle_of_contact(
                               home_base_sensor_touch_.angle_of_contact() + 90);
    change_angle = 0;
}
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
