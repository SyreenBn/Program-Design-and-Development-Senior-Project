/**
 * @file robot_battery.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_BATTERY_H_
#define SRC_ROBOT_BATTERY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
#include "src/common.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The battery for a robot.
 * @todo: implement depletion for movement and collision
 */
class RobotBattery {
 public:
  explicit RobotBattery(double max_charge) : charge_(max_charge),
                                             max_charge_(max_charge) {}

  /**
   * @brief All robots consume SOME power, even when just sitting there not moving.
   */
  double kBASE_DEPLETION = 0.1;

  /**
   * @brief The amount of energy consumed by the robot due to its linear speed
   * its is directly proportional to that speed, with a scaling factor.
   */
  double kLINEAR_SCALE_FACTOR = 0.01;
  /*
   * This funcition to reduce the charge of the battery when the robot hit
   * the obsecles
   */
  void reduceCharge(void) {
    if (charge_ >= 5) {
      charge_ = charge_ - 5;
    } else {
      charge_ = 0;
    }
  }
  /**
   * @brief The amount of energy consumed by the robot due to its angular speed
   * its is directly proportional to that speed, with a scaling factor.
   */
  double kANGULAR_SCALE_FACTOR = 0.01;

  /**
   * @brief Get the current battery level.
   */
  double level(void) const { return charge_; }

  /**
   * @brief Handle a recharge event by instantly restoring the robot's battery
   * to its maximum value.
   */
  void EventRecharge(void) { charge_ = max_charge_ + 5;
//  std::cout<< "The charge refilled, it is" << charge_ << "\n" << std::cout;
  }

  /**
   * @brief Reset the robot's battery to its newly constructed/undepleted state.
   */
  void Reset(void) {  charge_ = max_charge_ ; }

  /**
   * @brief Calculate the new battery level based on the current linear/angular speed.
   *
   * @param linear_vel The current linear speed, in m/s.
   * @param angular_vel The current angular speed, in rad/s.
   *
   * @return The updated battery level.
   */
  double Deplete(__unused Position old_pos,
    __unused Position new_pos, __unused double dt);

  // This is how the battery can be informed a collision occured.
  // Deplete accordingly.
  void Accept(EventCollision * e);
  /* to put the charge zero so the robot can not move even
   * if the user press the arrow keys
   */
  void setChargeZero(void) { charge_ = 0.00;}

 private:
  double charge_;
  double max_charge_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_BATTERY_H_
