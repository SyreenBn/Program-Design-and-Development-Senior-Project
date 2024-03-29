/**
 * @file robot_motion_behavior.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_behavior.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/* @brief this funcion is to plance the new position of hte enitity */
void RobotMotionBehavior::UpdatePosition(ArenaMobileEntity * const ent,
                                       unsigned int dt) {
  /* Save position for debugging purposes */
  Position new_pos = ent->get_pos();
  Position old_pos = ent->get_pos();
  /* Movement is always along the heading_angle (i.e. the hypotenuse) */
  new_pos.x += cos(ent->heading_angle()*M_PI/180.0)*ent->speed()*dt;
  new_pos.y += sin(ent->heading_angle()*M_PI/180.0)*ent->speed()*dt;
  ent->set_pos(new_pos);

  printf(
      "Updated %s kinematics: old_pos=(%d, %d), new_pos=(%d, %d)\n",
      ent->name().c_str(), old_pos.x, old_pos.y, new_pos.x, new_pos.y);
} /* update_position() */

/*
 * @brief This funcito is called when the user decide to restart the game again,
 * so the robot will return to the original place.
 */
void RobotMotionBehavior::UpdateOriginPosition(ArenaMobileEntity * const ent,
                                               float x, float y) {
  Position new_pos = ent->get_pos();
  Position old_pos = ent->get_pos();
  new_pos.x = x;
  new_pos.y = x;
  ent->set_pos(new_pos);
  printf(
      "Updated %s kinematics: old_pos=(%d, %d), new_pos=(%d, %d)\n",
      ent->name().c_str(), old_pos.x, old_pos.y, new_pos.x, new_pos.y);
} /* update_position() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
