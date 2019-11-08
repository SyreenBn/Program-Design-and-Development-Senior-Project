/**
 * @file player_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
PlayerMotionHandler::PlayerMotionHandler() :
  heading_angle_(0),
  speed_(0),
  max_speed_(5) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void PlayerMotionHandler::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
  /* this first situation is checkign the right arrow to incrase to
   * changed the heading  counter-clockwise
   */
  case COM_TURN_RIGHT :
  heading_angle_ =  heading_angle_ + 20;
    if (heading_angle_ <= 360) {
    heading_angle(heading_angle_);
    std::cout<< " The angle is changed the heading  counter-clockwise"
    <<std::endl;
  } else {
    heading_angle(heading_angle_ - 360);
  }
  break;
  /* this second situation is checkign the left arrow to
   * changed the heading  clockwise
   */
  case COM_TURN_LEFT :
         heading_angle_ =  heading_angle_ - 20;
        if (heading_angle_ <= 0) {
                heading_angle(heading_angle_ + 360);
                std::cout<< "The angle is changed the heading clockwise"
                <<std::endl;
        } else {
        heading_angle(heading_angle_);
    }
  break;
  /* this first situation is checkign the up arrow to incrase to
   * speed
   */
  case COM_SPEED_UP:
        speed_ = speed_ + 3.0;
        if (speed_ <= max_speed_) {
                speed(speed_);
    std::cout<< "The speed is increased" <<std::endl;
        } else {
                speed(max_speed_);
    }
  break;

  /* this first situation is checkign the down arrow to decrease to
   * speed
   */
  case COM_SLOW_DOWN:
  speed_ = speed_ - 1.5;
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

/* brief this function pass the new angle to the mobile enitities class*/
void PlayerMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.sensed()) {
    heading_angle_ = - st.angle_of_contact();
  }
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
