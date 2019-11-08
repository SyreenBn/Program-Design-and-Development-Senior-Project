/**
 * @file event_base_class.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_BASE_CLASS_H_
#define SRC_EVENT_BASE_CLASS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base event class from which all events should derive from.
 */
class EventBaseClass {
 public:
  EventBaseClass(void) {}
  virtual ~EventBaseClass(void) {}

  /**
   * @brief Each event, upon its firing, should emit a message to the user on
   * stdout saying what happened, in order to aid debugging.
   *
   */
Position point_of_contact() { return point_of_contact_; }
void point_of_contact(Position p) { point_of_contact_ = p; }
double angle_of_contact() { return angle_of_contact_; }
void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }
bool happened(void) {return happened_;}
void happened(bool h) {happened_ = h;}
//  virtual void EmitMessage(void) = 0;
void EmitMessage(void) {}
 private:
  bool happened_;
  Position point_of_contact_;
  double angle_of_contact_;
};

/*! Namespaces End */
/*! Namespaces End */
/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_BASE_CLASS_H_
