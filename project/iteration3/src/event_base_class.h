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

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base event class from which all events should derive from
 * this class used by ChangeOfState in arena.
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

/* to set and get the position of the event*/
virtual Position point_of_contact() = 0;
virtual void point_of_contact(Position p) = 0;

/* @brief to set and get the angle of the event*/
virtual double angle_of_contact() = 0;
virtual void angle_of_contact(double aoc) = 0;

/* @brief to set and get if the event happend or not*/
bool happened(void) {return happened_;}
void happened(bool h) {happened_ = h;}

/* @brief to set and get the id of the enities, all enitites return -1
 * exept the robot and the obesticals
 */
virtual int entity_id1(void)= 0;
virtual void entity_id1(int a) = 0;
virtual int entity_id2(void)= 0;
virtual void entity_id2(int a) = 0;

/*
 * @brief to set and get the id of the enities, each enitites has a char flag
 */
char ent1(void) {return ent1_;}
char ent2(void) {return ent2_;}
void ent1(char a) { ent1_ = a;}
void ent2(char b) { ent2_ = b;}

/*
 * @brief this function is to return the type of the event
 */
virtual char type(void) = 0;

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
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_BASE_CLASS_H_
