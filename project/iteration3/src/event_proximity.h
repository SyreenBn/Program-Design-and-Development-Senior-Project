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

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

 /**
  * @brief The EventProximity class is create the event when the robot is near
  * the other enitites to take the right raction
  */
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

  /*
   * @brief to set and get the id of the enities, each enitites has a char flag
   */
  int entity_id1(void) {return id1_;}
  void entity_id1(int a) {id1_ = a;}
  int entity_id2(void) {return id2_;}
  void entity_id2(int a) {id2_ = a;}
  char type(void) {return type_;}

 private:
  bool proximitied_;
  Position point_of_contact_;
  double angle_of_contact_;
  double ent1_raduis_;
  double ent2_raduis_;
  int id1_;
  int id2_;
  bool happened_;
  char type_ = 'x';
  char ent1_;
  char ent2_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_PROXIMITY_H_
