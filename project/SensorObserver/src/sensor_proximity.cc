/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_proximity.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorProximity::SensorProximity() :
  sensed_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0),
  range_(30) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorProximity::Accept(EventProximity * e) {
  // Determine if the sensor should be activated or inactivated.
  if (e->proximitied()) {
    sensed_ = true;
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    sensed_ = false;
  }
}


void SensorProximity::Accept(EventBaseClass * e) {
  // Determine if the sensor should be activated or inactivated.
  if (e->happened()) {
    sensed_ = true;
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    sensed_ = false;
  }
}

void SensorProximity::Reset(void) {
  sensed_ = false;
  angle_of_contact_ = 0.0;
  point_of_contact_.x = 0.0;
  point_of_contact_.y = 0.0;
} /* reset() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
