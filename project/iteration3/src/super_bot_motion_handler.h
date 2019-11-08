/**
 * @file actuator_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_SUPER_BOT_MOTION_HANDLER_H_
#define SRC_SUPER_BOT_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_commands.h"
#include "src/super_bot_params.h"
#include "src/arena_mobile_entity.h"
#include "src/sensor_touch.h"
#include "src/motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief The handler for the super_bot's actuators, which in this case are the two
 * wheel actuators. Its main job is to translate the directional commands from
 * the user into the appropriate differential drive wheel speeds.
 *
 * SuperBotMotionHandler manages the modification to the velocity based on
 * user input and collisions.
 * SuperBotMotionBehavior translates velocity and position to a new position.
 * Both of these are straightforward, but the framework allows for more
 * sophisticated models of motion in which each wheel has distinct speed.
 *
 * For this iteration, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class SuperBotMotionHandler : public MotionHandler {
 public:
  SuperBotMotionHandler();

  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   */
  void Reset(void) {
    heading_angle_ = 50;
    speed_ = 5;
  }

  /**
  * @brief Change the speed and direction according to the sensor readings.
  *
  * @param touch sensor that can be activated and contains point-of-contact.
  *
  */
  void UpdateVelocity(SensorTouch st);

  /* @brief to set and get the speed */
    double speed() { return speed_; }
    void speed(double sp) {
      speed_ = sp; }

    /* @brief to set and get the heading_angle */
    double heading_angle() const { return heading_angle_;}
    void heading_angle(double ha) { heading_angle_ = ha; }

    /* @brief to set and get the max_speed */
    double max_speed() { return max_speed_; }
    void max_speed(double ms) { max_speed_ = ms; }

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif   // SRC_SUPER_BOT_MOTION_HANDLER_H_
