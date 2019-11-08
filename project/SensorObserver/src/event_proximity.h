/**
 * @file event_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */


#ifndef SRC_EVENT_PROXIMITY_H_
#define SRC_EVENT_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <stdlib.h>
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class EventProximity : public EventBaseClass {
 public:
  EventProximity();
  void EmitMessage(void);
/*
* return ture if the porximity event is happened
*/
  bool proximitied(void) { return proximitied_; }
  void proximitied(bool p) { proximitied_ = p; }
  bool happened(void) {return proximitied_;}
  void happened(bool h) {proximitied_ = h;}
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

  Position ent1_orignal_event_position(){return ent2_orignal_event_position_;}
  Position ent2_orignal_event_position(){return ent2_orignal_event_position_;}
  enum entity_type second_entity_type(){return second_entity_type_;}
  void second_entity_type(enum entity_type a){ second_entity_type_ = a;}

  void first_entity_type(enum entity_type a){ first_entity_type_ = a;}
  enum entity_type first_entity_type(){return first_entity_type_;}

//  int ent1(){return ent1_;}
  double ent1_raduis(){return ent1_raduis_;}
  double ent2_raduis(){return ent2_raduis_;}

  int entity_id1(void){return id1_;}
  void entity_id1(int a){id1_ = a;}
  int entity_id2(void){return id2_;}
  void entity_id2(int a){id2_ = a;}
  char type(void){return type_;}

  char ent1(void){return ent1_;}
  char ent2(void){return ent2_;}
  void ent1(char a){ ent1_ = a;}
  void ent2(char b){ ent2_ = b;}

 private:
  bool proximitied_;
  Position point_of_contact_;
  double angle_of_contact_;
  enum entity_type second_entity_type_;
  enum entity_type first_entity_type_;
  Position ent1_orignal_event_position_;
  Position ent2_orignal_event_position_;
  double ent1_raduis_;
  double ent2_raduis_;
  //int ent1_;
  int id1_;
  int id2_;
  Position p_;
  bool happened_;
  char type_ = 'x';
  char ent1_;
  char ent2_;
};


NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_PROXIMITY_H_
