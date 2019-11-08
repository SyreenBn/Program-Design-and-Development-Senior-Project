/**
 * @file event_distress_call.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */


#ifndef SRC_EVENT_DISTRESS_CALL_H_
#define SRC_EVENT_DISTRESS_CALL_H_
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

class EventDistressCall : public EventBaseClass {
 public:
  EventDistressCall();
  void EmitMessage(void);
  bool distressed() { return distressed_; }
  void distressed(bool d) { distressed_ = d; }
  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }
  double angle_of_contact() { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }

 private:
  bool distressed_;
  Position point_of_contact_;
  double angle_of_contact_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  //  SRC_EVENT_DISTRESS_CALL_H_
