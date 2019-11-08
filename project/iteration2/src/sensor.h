/**
 * @file sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SENSOR_H_
#define SRC_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <utility>

#include "src/common.h"
#include "src/arena_entity.h"
#include "src/event_base_class.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
class ArenaEntity;

/**
 * @brief A representation of a sensor. it is the parent calss of all sensors
 * of all mobile entities
 *
 */
class Sensor {
 public:
Sensor();

  /**
   * @brief Get the current activation reading from the sensor.
   */
bool sensed(void) {return sensed_;}
void sensed(bool value) {sensed_ = value;}
void Accept(EventBaseClass * e);
//   void Accept (EventBaseClass * e,
//                class ArenaEntity* const ent1, double requied_distance );
// // /*
//   virtual Position point_of_contact() = 0;
//   virtual void point_of_contact(Position p) = 0;
//
//   virtual double angle_of_contact(void) = 0;
//   virtual void angle_of_contact(double aoc) = 0;

  /**
   * @brief Compute a new reading based on the collision event.
   *
   * Note that collision events can report "no collision" which
   * will inactivate the sensor.
   *
   */

//  virtual void Accept(EventCollision * e) = 0;

// (const ArenaEntity* const ent1,
//   const ArenaEntity* const ent2,
//   EventCollision * event,
//   double collision_delta)

  /**
   * @brief Reset the proximity sensor to its newly constructed state.
   */
void Reset(void) {sensed_ = false;}
virtual void Update(const EventBaseClass * e) {}
virtual EventBaseClass * read(void) {return event_;}

 private:
  EventBaseClass * event_;
  const ArenaEntity * entity_;
  float range_;
  bool sensed_;
  Position point_of_contact_;
  double angle_of_contact_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_SENSOR_H_
