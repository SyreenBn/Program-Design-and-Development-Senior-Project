/**
 * @file arena_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 */

#ifndef SRC_ARENA_PARAMS_H_
#define SRC_ARENA_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player_params.h"
#include "src/robot_params.h"
#include "src/home_base_params.h"
#include "src/super_bot_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
/*! The number of the obstacles */
#define MAX_OBSTACLES 8
#define MAX_ROBOTS 6


/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
struct arena_params {
  struct player_params player;
  struct super_bot_params super_bot;
  //  the robot params become an array because we have 5
  struct robot_params robot[MAX_ROBOTS];
  struct arena_entity_params recharge_station;
  struct home_base_params home_base;
  struct arena_entity_params obstacles[MAX_OBSTACLES];

  size_t n_obstacles;
  size_t n_robots;  //  the numver of the orobot because we have 5

  uint x_dim;
  uint y_dim;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_PARAMS_H_
