/**
 * @file player_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "src/player_battery.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double PlayerBattery::Deplete(__unused Position old_pos,
   __unused Position new_pos, __unused double dt) {
/* @todo deplete battery by some value based on movement and speed */
double dist = std::sqrt(
     std::pow((old_pos.x - new_pos.x), 2) +
     std::pow((old_pos.y - new_pos.y), 2));
/*
 * We find the speed form the distance and the time
 */
double speed = dist / dt;
/*
 * the depletion process depends on the speed and the distace.
 */
double depleteAmount = (speed*kLINEAR_SCALE_FACTOR) +
             (dist*kANGULAR_SCALE_FACTOR) +
             (kBASE_DEPLETION);
if (dist > 0 && charge_ > 0) {
     charge_ = charge_ - depleteAmount;
if (charge_ > 0) {
       charge_ = charge_;
} else {charge_ = 0.0;}
}
  return charge_;
} /* deplete() */

/**
 * Accept this funciton to accept the colosion if happened while recharging the
 * player
 */
void Accept(__unused EventCollision * e) {}

/*! Namespaces End */
NAMESPACE_END(csci3081);
