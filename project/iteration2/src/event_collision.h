/**
 * @file event_collision.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COLLISION_H_
#define SRC_EVENT_COLLISION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdlib.h>
#include <string>

#include "src/event_base_class.h"
#include "src/entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class EventCollision : public EventBaseClass {
 public:
  EventCollision();
  EventCollision
  (const int entity1,
   const Position p,
   const Position q,
   const enum entity_type second_entity) {
      second_entity_type = second_entity;
      ent1_orignal_event_position = p;
      ent2_orignal_event_position = q;
      ent1 = entity1;
  }
  void EmitMessage(void);
  bool collided() { return collided_; }
  void collided(bool c) { collided_ = c; }
  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }
  double angle_of_contact() { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

 private:
  bool collided_;
  Position point_of_contact_;
  double angle_of_contact_;
  enum entity_type second_entity_type;
  Position ent1_orignal_event_position;
  Position ent2_orignal_event_position;
  int ent1;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_COLLISION_H_
