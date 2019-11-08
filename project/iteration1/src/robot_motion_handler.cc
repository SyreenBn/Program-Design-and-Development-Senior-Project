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
void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
  case COM_TURN_RIGHT :
  heading_angle_ =  heading_angle_ + 10;
    if (heading_angle_ <= 360) {
    heading_angle(heading_angle_);
    std::cout<< " The angle is changed the heading  counter-clockwise"
    <<std::endl;
  } else {
    heading_angle(heading_angle_ - 360);
  }
  break;
  case COM_TURN_LEFT :
         heading_angle_ =  heading_angle_ - 10;
        if (heading_angle_ <= 0) {
                heading_angle(heading_angle_ + 360);
                std::cout<< "The angle is changed the heading clockwise"
                <<std::endl;
        } else {
        heading_angle(heading_angle_);
    }
  break;
  case COM_SPEED_UP:
        speed_ = speed_ + 1.0;
        if (speed_ <= max_speed_) {
                speed(speed_);
    std::cout<< "The speed is increased" <<std::endl;
        } else {
                speed(max_speed_);
    }
  break;
  case COM_SLOW_DOWN:
  speed_ = speed_ - 0.5;
        if (speed_ <= 0) {
                speed(0);
                std::cout<< "The speed is decreased" <<std::endl;
        } else {
          speed(speed_);
        }
  break;
  default:
    std::cerr << "FATAL: bad actuator command" << std::endl;
    assert(0);
  } /* switch() */
} /* accept_command() */

void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle_ = - st.angle_of_contact();
  }
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
