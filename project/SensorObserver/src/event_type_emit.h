/**
 * @file event_type_emit.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_TYPE_EMIT_H_
#define SRC_EVENT_TYPE_EMIT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdlib.h>
#include "src/event_base_class.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The event type emit is a  class to check the event the entity and provide information regarding the entities involved and the location of the event.
 */

class EventEntityTypeEmit : public EventBaseClass {
 public:
  EventEntityTypeEmit();
  EventEntityTypeEmit(int id, Position p, enum entity_type ent_type){
  id_ = id;
  p_ = p;
  ent_type_ = ent_type;
  }


  void EmitMessage(void);

  /*
* return ture if the event is emited and false if not
*/

  bool Emitted(void) { return emitted_; }
  void Emitted(bool e) { emitted_ = e; }

 /*
   * this fuction is to the position of contact of the event
   */

  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }

  /*
   * this fuction is to the angle of contact of the event
   */

  double angle_of_contact() { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

 private:
  bool emitted_;
  Position point_of_contact_;
  double angle_of_contact_;
  int id_;
  Position p_;
  enum entity_type ent_type_;
};


NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_TYPE_EMIT_H_
