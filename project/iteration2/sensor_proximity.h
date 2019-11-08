/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_PROXIMITY_H_
#define SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include "src/sensor.h"
#include "src/common.h"
//#include "src/event_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

class SensorProximity : public Sensor {
 public:
  SensorProximity( const ArenaMobileEntity * a, float range, float field);

  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }
  int output(){
    if (activated_){ return -1;}
    else {return 0;}}

  float range(void) { return range_; }
  void range(float ran) { range_ = ran; }

  float field(void) { return field_; }
  void field(float fld) { field_ = fld; }

  void Accept(EventProximity * e);

  void Reset(void);

 private:
  bool activated_;
  float range_;
  float field_;
};

NAMESPACE_END(csci3081);

#endif   // SRC_SENSOR_TOUCH_H_
