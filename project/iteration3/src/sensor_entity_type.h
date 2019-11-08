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
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Classes
 ******************************************************************************/
/*
 * @ brief This class to register the type of the enitities which the event happened
 * between but I didi not use this class in my project
 */
class SensorEntityType : public Sensor {
 public:
  SensorEntityType():
  sensed_(false),
  range_(0.0) { }
  ~SensorEntityType() {}

  /**
   * @brief Get the current activation reading from the sensor.
   */
  bool sensed(void) { return sensed_; }
  void sensed(bool value) { sensed_ = value; }

  /*
   * @brief this fuction is to set and get the range of the sensor
   */
  float range(void) { return range_; }
  void range(float ran) { range_ = ran; }

  /*
   * @brief this fuction set the type of the enitity
   */
  void output(enum entity_type a) {
  if (a = kRobot) {key_= 1;
    } else if (a = kSuperBot) {key_= 2;
    } else if (a = kPlayer) {key_= 3;
    } else if (a = kHomeBase) {key_= 4;
    } else if (a = kRechargeStation) {key_= 5;
    } else if (a = kWall) {key_= 6;}
    }

    /*
     * @brief this fuction return the type of the enitity
     */
  int output (void) {return key_;}

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
  void Reset() {}

 private:
  double range_;
  bool sensed_;
  int key_;
  enum entity_type ent;
};

NAMESPACE_END(csci3081);

#endif  //  SRC_SENSOR_ENTITY_TYPE_H_
