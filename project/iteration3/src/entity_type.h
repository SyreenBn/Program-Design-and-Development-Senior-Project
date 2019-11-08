/**
 * @file entity_type.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef SRC_ENTITY_TYPE_H_
#define SRC_ENTITY_TYPE_H_

#include "src/common.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
  * @brief this enumuraiton is to return the type of the entity to help the
  * parent senor recognize the entity ot pass the event
  */
enum entity_type {
  kRobot,
  kSuperBot,
  kPlayer,
  kHomeBase,
  kRechargeStation,
  kObstacle,
  kWall
};
/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ENTITY_TYPE_H_
