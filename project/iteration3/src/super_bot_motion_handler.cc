/**
 * @file super_bot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/super_bot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SuperBotMotionHandler::SuperBotMotionHandler() :
  heading_angle_(0),
  speed_(0),
  max_speed_(5) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

 /* brief this function place the new angle to the mobile enitities class
  * each sonsor has an angle of an event
  */
void SuperBotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.sensed()) {
    heading_angle_ = - st.angle_of_contact();
  }
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
