/**
 * @file super_bot_motion_behavior.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SUPER_BOT_MOTION_BEHAVIOR_H_
#define SRC_SUPER_BOT_MOTION_BEHAVIOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <Eigen/Dense>
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class SuperBotMotionBehavior {
 public:
  SuperBotMotionBehavior(void) {}

  /**
   * @brief Update the position for an ArenaEntity, based on its current
   * position and velocity.
   *
   * SuperBotMotionHandler manages the modification to the velocity based on
   * user input and collisions.
   * SuperBotMotionBehavior translates velocity and position to a new position.
   * Both of these are straightforward, but the framework allows for more
   * sophisticated models of motion in which each wheel has distinct speed.
   *
   * @param[in] ent The entitity to update.
   */
  void UpdatePosition(class ArenaMobileEntity * const ent, uint dt);

   /* this funcion to reset the super_bot to the original place when the user
    *restart the game
    */
  void UpdateOriginPosition(class ArenaMobileEntity * const ent);
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_SUPER_BOT_MOTION_BEHAVIOR_H_
