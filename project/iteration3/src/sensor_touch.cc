/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_touch.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch() :
  sensed_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
******************************************************************************/

/* @brief this funcito is to accept the event form the mobile entiities*/
void SensorTouch::Accept(EventCollision * e) {
// Determine if the sensor should be activated or inactivated.
if (e->happened()) {
  sensed_ = true;
  point_of_contact_ = e->point_of_contact();
  angle_of_contact_ = e->angle_of_contact();
} else {
  sensed_ = false;
}
}

/* @brief this funcito is to accept the base event form the robot*/
void SensorTouch::Accept(EventBaseClass * e) {
// Determine if the sensor should be activated or inactivated.
if (e->happened()) {
  sensed_ = true;
  point_of_contact_ = e->point_of_contact();
  angle_of_contact_ = e->angle_of_contact();
} else {
  sensed_ = false;
}
}

/* @brief thid funcito is to reset the senosr to the original sitaution */
void SensorTouch::Reset(void) {
  sensed_ = false;
  angle_of_contact_ = 0.0;
  point_of_contact_.x = 0.0;
  point_of_contact_.y = 0.0;
} /* reset() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
