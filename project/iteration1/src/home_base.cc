/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/home_base.h"
#include "src/home_base_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
HomeBase::HomeBase(const struct home_base_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
    params->pos, params->color),
  heading_angle_(0),
  angle_delta_(params->angle_delta) {}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void HomeBase::Accept(EventRecharge * e) {
  Accept(e);
}
// Pass along a collision event (from arena) to the home base touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void HomeBase::Accept(EventCollision * e) {
  home_base_sensor_touch_.Accept(e);
}

void HomeBase::Reset(void) {
  motion_handler_.Reset();
  home_base_sensor_touch_.Reset();
  motion_behavior_.UpdateOriginPosition(this);
}  /* Reset() */

void HomeBase::TimestepUpdate(uint dt) {
  // Update heading and speed as indicated by home base touch sensor
  motion_handler_.UpdateVelocity(home_base_sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
} /* TimestepUpdate() */  // extra quase

/*! Namespaces End */
NAMESPACE_END(csci3081);
