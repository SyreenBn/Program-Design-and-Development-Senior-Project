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
#include "src/entity_type.h"


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
virtual Position point_of_contact() = 0;
virtual void point_of_contact(Position p) = 0;
virtual double angle_of_contact() = 0;
virtual void angle_of_contact(double aoc) = 0;
bool happened(void) {return happened_;}
void happened(bool h) {happened_ = h;}
virtual int entity_id1(void)= 0;
virtual void entity_id1(int a) = 0;
virtual int entity_id2(void)= 0;
virtual void entity_id2(int a) = 0;
Position ent1_orignal_event_position(){return ent2_orignal_event_position_;}
Position ent2_orignal_event_position(){return ent2_orignal_event_position_;}
virtual enum entity_type second_entity_type() = 0;
virtual enum entity_type first_entity_type() = 0;
//int ent1(){return ent1;}
char ent1(void){return ent1_;}
char ent2(void){return ent2_;}
void ent1(char a){ ent1_ = a;}
void ent2(char b){ ent2_ = b;}

// virtual char ent1(void) = 0;
// virtual char ent2(void) = 0;
// virtual void ent1(char a) = 0;
// virtual void ent2(char b) = 0;



virtual char type(void) = 0;
//  virtual void EmitMessage(void) = 0;
void EmitMessage(void) {}
 private:
  bool happened_;
  Position point_of_contact_;
  double angle_of_contact_;
  enum entity_type second_entity_type_;
  Position ent1_orignal_event_position_;
  Position ent2_orignal_event_position_;
  double ent1_raduis_;
  double ent2_raduis_;
  char ent1_;
  char ent2_;
};

/*! Namespaces End */
/*! Namespaces End */
/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_BASE_CLASS_H_
