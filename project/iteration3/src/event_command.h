/**
 * @file actuator_cmd_event.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_EVENT_COMMAND_H_
#define SRC_EVENT_COMMAND_H_

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
 * @brief This class to accept the command for the user when the user press the
 * arrows keypress.
 */
class EventCommand : public EventBaseClass {
 public:
  explicit EventCommand(enum event_commands cmd) : cmd_(cmd) {}

  void EmitMessage(void) { printf("Motion cmd %d received\n", cmd_); }
  enum event_commands cmd(void) const { return cmd_; }

 private:
  enum event_commands cmd_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_EVENT_COMMAND_H_
