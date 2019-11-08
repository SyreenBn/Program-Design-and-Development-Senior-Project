/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include "src/robot_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
    params->pos, params->color),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  sensor_distress_(),
  id_(-1) {
  motion_handler_.heading_angle(270);
  motion_handler_.speed(5);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(uint dt) {
  if (moving_around_) {
  Position old_pos = get_pos();
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
}
} /* TimestepUpdate() */


// Pass along a collision event (from arena) to the touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void Robot::Accept(EventCollision * e) {
  sensor_touch_.Accept(e);
}
/*
* Pass along a proximity event (from sensor) to the left_sensor_proximity and right_sensor_proximity.
* This method provides a framework in which sensors can get different
* types of information from different sources.
*/
void Robot::Accept(EventProximity * e) {
left_sensor_proximity_.Accept(e);
right_sensor_proximity_.Accept(e);
}

/*
* Pass along a distress event (from sensor) to the sensor_distress
* This method provides a framework in which sensors can get different
* types of information from different sources.
*/


void Robot::Accept(EventDistressCall * e) {
sensor_distress_.Accept(e);
}

void Robot::Accept(EventRecharge * e) {
  Accept(e);
}

/*
* resent the robot to the orignal situaiton
*/
void Robot::Reset(void) {
  motion_handler_.Reset();
  sensor_touch_.Reset();

/*@bug
 * all roboot reset to one positon in the upper left of the arena
 */
//  motion_behavior_.UpdateOriginPosition(this);
} /* Reset() */


/*! Namespaces End */
NAMESPACE_END(csci3081);
