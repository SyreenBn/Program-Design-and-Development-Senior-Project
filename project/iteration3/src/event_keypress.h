/**
 * @file event_keypress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_KEYPRESS_H_
#define SRC_EVENT_KEYPRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "src/event_base_class.h"
#include "src/event_commands.h"

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
 * @brief This class to accept the press of the keyboard keys and take the right
 * raction.
 */
class EventKeypress : public EventBaseClass {
 public:
  explicit EventKeypress(int key) : key_(key) {}
  void EmitMessage(void) { printf("Keypress command received\n"); }

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
   * @brief to set and get the id of the enities, each enitites has a char flag
   * these funciton does not use her but I need to create them beccause
   * it derive form the base event calss
   */
  int entity_id1(void) {return id1_;}
  void entity_id1(int a) {id1_ = a;}
  int entity_id2(void) {return id2_;}
  void entity_id2(int a) {id2_ = a;}

  /*
   * @brief happened to set and get the situation of the evnet but it is the general one
   * these funciton does not use her but I need to create them beccause
   * it derive form the base event calss
   */
  bool happened(void) {return happened_;}
  void happened(bool h) {happened_ = h;}

  /*
   * @brief this function is to return the type of the event
   * these funciton does not use her but I need to create them beccause
   * it derive form the base event calss
   */
  char type(void) {}

  int get_key(void) const {return key_;}
  /*
   * This function is moved form the private to the public, so I can call it in
   *other calss as I did in the arena calss.
   */
  enum event_commands get_key_cmd(int key) const;

 private:
  bool happened_;
  int id1_;
  int id2_;
  int key_;
  Position point_of_contact_;
  double angle_of_contact_;

  EventKeypress& operator=(const EventKeypress& other) = delete;
  EventKeypress(const EventKeypress& other) = delete;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_KEYPRESS_H_
