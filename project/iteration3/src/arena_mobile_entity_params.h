/**
 * @file arena_mobile_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_PARAMS_H_
#define SRC_ARENA_MOBILE_ENTITY_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
 /** @brief arena_mobile_entity_params is to stor the information of the
   * mobile enititis such as player homebase and robots and superbot
   * it store the collision_delta of all these enitities to use it when we need
   * to check the collision
   */
struct arena_mobile_entity_params : public arena_entity_params {
  arena_mobile_entity_params(void) : arena_entity_params(),
                               collision_delta() {}

  double collision_delta;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_MOBILE_ENTITY_PARAMS_H_