/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
  heading_angle_(0),
  speed_(0),
  max_speed_(5) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void RobotMotionHandler::UpdateVelocity(SensorTouch st, SensorProximity sp) {
  if (st.sensed()) {
    heading_angle_ = -st.angle_of_contact();
  }
  if (sp.sensed()){
    heading_angle_ = -st.angle_of_contact();
  }
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
