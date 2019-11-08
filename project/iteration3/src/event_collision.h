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
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
  * @brief The collision event class is create the event between twoenitites
  * when the distance is zero between them
  */
class EventCollision : public EventBaseClass {
 public:
  EventCollision();

  /*
   * @brief EmitMessage to print the point of contact and the angle of contact
   */
  void EmitMessage(void);

  /*
   * @brief collided to set and get the situation of the evnet
   */
  bool collided() { return collided_; }
  void collided(bool c) { collided_ = c; }

  /*
   * @brief point_of_contact to set and get the position of the evnet
   */
  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }

  /*
   * @brief angle_of_contact to set and get the angle of the evnet
   */
  double angle_of_contact() { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

  /*
   * @brief happened to set and get the situation of the evnet but it is the general one
   */
  bool happened(void) {return collided_;}
  void happened(bool h) {collided_ = h;}

  /*
   * @brief to set and get the id of the enities, each enitites has a char flag
   */
  int entity_id1(void) {return id1_;}
  void entity_id1(int a) {id1_ = a;}
  int entity_id2(void) {return id2_;}
  void entity_id2(int a) {id2_ = a;}

  /*
   * @brief this function is to return the type of the event
   */
  char type(void) {return type_;}

 private:
  bool collided_;
  Position point_of_contact_;
  double angle_of_contact_;
  int id1_;
  int id2_;
  char type_ = 'c';
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_COLLISION_H_
