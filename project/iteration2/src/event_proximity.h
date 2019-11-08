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
  bool proximitied_;
  Position point_of_contact_;
  double angle_of_contact_;
};


NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_PROXIMITY_H_
