/**
 * @file super_bot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SUPER_BOT_PARAMS_H_
#define SRC_SUPER_BOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
struct super_bot_params : public arena_mobile_entity_params {
  super_bot_params(void) :
      arena_mobile_entity_params(),
      angle_delta() {}
  double speed_delta;
  double max_speed;
  uint angle_delta;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_SUPER_BOT_PARAMS_H_
