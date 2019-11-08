/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_distress.h"
#include "src/arena_entity.h"
#include "src/event_distress_call.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorDistress::SensorDistress():
  sensed_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorDistress::Accept(EventDistressCall * e) {
  // Determine if the sensor should be activated or inactivated.
  if (e->distressed()) {
    sensed_ = true;
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    sensed_ = false;
  }
}

void SensorDistress::Reset(void) {
  sensed_ = false;
  angle_of_contact_ = 0.0;
  point_of_contact_.x = 0.0;
  point_of_contact_.y = 0.0;
} /* reset() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
