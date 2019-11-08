/**
 * @file arena_mobile_entity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity.h"
#include "src/robot_motion_behavior.h"
#include "src/home_base_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void ArenaMobileEntity::TimestepUpdate(uint dt) {
  RobotMotionBehavior h;
  h.UpdatePosition(this, dt);
  /**
   * @brief Informs the location of the home base will updeate by calling the
   * UpdatePosition of home_base_motion_handler
   * this funciton take the home base entity and the time and return the home
   * base in the new position
   */
  HomeBaseMotionBehavior h1;
  h1.UpdatePosition(this, dt);
} /* TimestepUpdate() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
