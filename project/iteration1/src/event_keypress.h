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

  int get_key(void) const {return key_;}
  /*
   * This function is moved form the private to the public, so I can call it in
   *other calss as I did in the arena calss.
   */
  enum event_commands get_key_cmd(int key) const;

 private:
  int key_;

  EventKeypress& operator=(const EventKeypress& other) = delete;
  EventKeypress(const EventKeypress& other) = delete;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_KEYPRESS_H_
