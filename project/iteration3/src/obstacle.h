/**
 * @file obstacle.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_OBSTACLE_H_
#define SRC_OBSTACLE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/arena_immobile_entity.h"
#include "src/color.h"
#include "src/sensor_entity_type.h"
#include "src/entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Obstacle: public ArenaImmobileEntity {
 public:
  Obstacle(double radius, const Position& pos,
                   const Color& color);

/* @brief this funcito is to print the nameof hte obseticals
 * and the id on the ciercle
 */
  std::string name(void) const {
    return "Obstacle" + std::to_string(id_);
  }

  /* @brief it is return -1 when the event clall this function in arena*/
  const int& get_id(void) const { return id__; }

  /* @brief it is return the char of the enitity type to use it in the robot
   * when checking the senarios of collision
   */
  const char& entity_type(void) const {return entity_type_;}

 private:
  static uint next_id_;
  int id_;
  int id__ = -1;
  char entity_type_ = 'o';
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_OBSTACLE_H_
