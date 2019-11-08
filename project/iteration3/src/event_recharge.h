/**
 * @file event_recharge.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_RECHARGE_H_
#define SRC_EVENT_RECHARGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief this event is credated when the player hit the reacchrge station
 */
class EventRecharge : public EventBaseClass {
 public:
  EventRecharge(void) {}
/*
* this funciton to tell the user than the battery is recharged when it hit the recharge station
*/
void EmitMessage(void) { printf("Player Battery recharged!\n"); }
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
bool happened(void) {return happened_;}
void happened(bool h) {happened_ = h;}

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
char type(void) {}

 private:
  Position point_of_contact_;
  double angle_of_contact_;
  bool happened_;
  int id1_;
  int id2_;
};
/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_RECHARGE_H_
