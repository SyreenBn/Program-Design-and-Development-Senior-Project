/**
 * @file sensor_distress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_ENTITY_TYPE_H_
#define SRC_SENSOR_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>
#include "src/sensor.h"
#include "src/common.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
// class ArenaEntity;
//
//
//
class SensorEntityType : public Sensor {
 public:
  SensorEntityType():
  sensed_(false),
  range_(0.0) { }
  ~SensorEntityType() {}

  bool sensed(void) { return sensed_; }
  void sensed(bool value) { sensed_ = value; }
  float range(void) { return range_; }
  void range(float ran) { range_ = ran; }

  // enum entity_type output() {
  //   if (key_ = 1) {return kRobot;}
  //   else if (key_ = 2){return kSuperBot;}
  //   else if (key_ = 3){return kPlayer;}
  //   else if (key_ = 4){return kHomeBase;}
  //   else if (key_ = 5){return kRechargeStation;}
  //   else {return kWall;}
  //  }
  void output(enum entity_type a) {
  if (a = kRobot) {key_= 1;
    } else if (a = kSuperBot) {key_= 2;
    } else if (a = kPlayer) {key_= 3;
    } else if (a = kHomeBase) {key_= 4;
    } else if (a = kRechargeStation) {key_= 5;
    } else if (a = kWall) {key_= 6;}
    }
  int output (void) {return key_;}
//
  // enum entity_type output() {
  //   return ent;
  // }
  // void output(enum entity_type a){
  //   ent = a;
//   }
  void Reset() {}
//
 private:
  double range_;
  bool sensed_;
  int key_;
  enum entity_type ent;
};

NAMESPACE_END(csci3081);

#endif  //  SRC_SENSOR_ENTITY_TYPE_H_
