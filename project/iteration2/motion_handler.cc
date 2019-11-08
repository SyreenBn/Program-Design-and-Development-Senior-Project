/**
 * @file actuator motion_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
 #include "src/robot_motion_handler.h"
 #include "src/home_base_motion_handler.h"
 #include "src/motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/

MotionHandler::MotionHandler() :
    heading_angle_(0),
    speed_(0),
    max_speed_(5) {
  }


/*! Namespaces End */
NAMESPACE_END(csci3081);
