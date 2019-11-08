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
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief @todo
 */
class EventKeypress : public EventBaseClass {
 public:
  explicit EventKeypress(int key) : key_(key) {}
  void EmitMessage(void) { printf("Keypress command received\n"); }

  Position point_of_contact() { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }
  double angle_of_contact() { return angle_of_contact_; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }
  int entity_id1(void){return id1_;}
  void entity_id1(int a){id1_ = a;}
  int entity_id2(void){return id2_;}
  void entity_id2(int a){id2_ = a;}
  enum entity_type second_entity_type(){return second_entity_type_;}
  enum entity_type first_entity_type(){return first_entity_type_;}
  bool happened(void) {return happened_;}
  void happened(bool h) {happened_ = h;}
  char type(void) {}

  int get_key(void) const {return key_;}
  /*
   * This function is moved form the private to the public, so I can call it in
   *other calss as I did in the arena calss.
   */
  enum event_commands get_key_cmd(int key) const;

  char ent1(void){return ent1_;}
  char ent2(void){return ent2_;}
  void ent1(char a){ ent1_ = a;}
  void ent2(char b){ ent2_ = b;}

 private:
   bool happened_;
   int id1_;
   int id2_;
  int key_;
  Position point_of_contact_;
  double angle_of_contact_;
  enum entity_type second_entity_type_;
  enum entity_type first_entity_type_;
  EventKeypress& operator=(const EventKeypress& other) = delete;
  EventKeypress(const EventKeypress& other) = delete;
  char ent1_;
  char ent2_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_KEYPRESS_H_
