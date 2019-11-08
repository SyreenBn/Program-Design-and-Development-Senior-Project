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
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Obstacle: public ArenaImmobileEntity {
 public:
  Obstacle(double radius, const Position& pos,
                   const Color& color);

  std::string name(void) const {
    return "Obstacle" + std::to_string(id_);
  }
//  enum entity_type entityType(void) {return entity_type_;}
  const int& get_id(void) const { return id__; }
  const char& entity_type(void) const {return entity_type_;}


 private:
  static uint next_id_;
  //enum entity_type entity_type_ = kObstacle;
  int id_;
  int id__ = -1;
  char entity_type_ = 'o';
};

NAMESPACE_END(csci3081);

#endif  // SRC_OBSTACLE_H_
