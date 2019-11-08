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

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
  * @brief The distress call event class is create the event when the robot is
  * frozen at a position
  */
class EventDistressCall : public EventBaseClass {
 public:
  EventDistressCall();
  EventDistressCall(int id, Position p) {
    id_ = id;
    p_ = p;
  }
  /*
   * @brief EmitMessage to print the point of contact and the angle of contact
   */
  void EmitMessage(void);

  /*
   * @brief distressed to set and get the situation of the evnet
   */
  bool distressed() { return distressed_; }
  void distressed(bool d) { distressed_ = d; }

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
   * @brief this function is to return the type of the event
   */
  char type(void) {return type_;}

  /*
   * @brief happened to set and get the situation of the evnet but it is the general one
   */
  bool happened(void) {return distressed_;}
  void happened(bool h) {distressed_ = h;}

  /*
   * @brief to set and get the id of the enities, each enitites has a char flag
   */
  int entity_id1(void) {return id1_;}
  void entity_id1(int a) {id1_ = a;}
  int entity_id2(void) {return id2_;}
  void entity_id2(int a) {id2_ = a;}

 private:
  bool distressed_;
  Position point_of_contact_;
  double angle_of_contact_;
  char type_ = 'd';
  int id2_;
  int id1_;
  int id_;
  Position p_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  //  SRC_EVENT_DISTRESS_CALL_H_
