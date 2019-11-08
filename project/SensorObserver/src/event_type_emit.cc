/**
 * @file event_type_emit.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_type_emit.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventEntityTypeEmit::EventEntityTypeEmit() :
  emitted_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
/*
* this function is to print the point and angle of the event
*/
void EventEntityTypeEmit::EmitMessage(void) {
  printf("Entity Type Emit event at point %d %d. Angle %f",
  point_of_contact_.x, point_of_contact_.y, angle_of_contact_);
} /* EmitMessage() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
