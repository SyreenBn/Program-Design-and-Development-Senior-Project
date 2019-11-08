/**
 * @file super_bot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/super_bot.h"
#include "src/super_bot_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint SuperBot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SuperBot::SuperBot(const struct super_bot_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
    params->pos, params->color),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  sensor_distress_(),
  id_(-1) {
  motion_handler_.heading_angle(70);
  motion_handler_.speed(5);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void SuperBot::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
} /* TimestepUpdate() */


// Pass along a collision event (from arena) to the touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void SuperBot::Accept(EventCollision * e) {
  sensor_touch_.Accept(e);
}

void SuperBot::Reset(void) {
  motion_handler_.Reset();
  sensor_touch_.Reset();
  motion_behavior_.UpdateOriginPosition(this);
} /* Reset() */


/*! Namespaces End */
NAMESPACE_END(csci3081);
