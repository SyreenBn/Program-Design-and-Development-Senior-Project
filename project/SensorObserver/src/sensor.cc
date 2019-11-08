/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor.h"
#include "src/arena_entity.h"
#include "src/robot.h"
#include "src/arena.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);
class Arena;
/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Sensor::Sensor() :
  sensed_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}


 void Sensor::Accept(EventBaseClass * e){
   if (e->happened()) {
     sensed_ = true;
     point_of_contact_ = e->point_of_contact();
     angle_of_contact_ = e->angle_of_contact();
   } else {
     sensed_ = false;
   }
 }

/*! Namespaces End */
NAMESPACE_END(csci3081);
