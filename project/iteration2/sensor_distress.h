/**
 * @file sensor_distress.h
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
//#include "src/event_distress.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;



class SensorDistress  : public Sensor {
public:
  SensorDistress(const ArenaMobileEntity * entity, double range)
  void Accept(const EventDistress & ed);
  bool activated(void) { return activated_; }
  void activated(bool value) { activated_ = value; }
  int Output() {
    if (activated_) {return 1;}
    else {return 0;} }
private:
  double range_;
  bool activated_;
};
