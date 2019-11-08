/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot_motion_handler.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Robot : public ArenaMobileEntity {
 public:
  explicit Robot(const struct robot_params* const params);

  void ResetBattery(void);
  void Reset(void);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  void TimestepUpdate(unsigned int dt);
  void Accept(EventRecharge * e);
  void Accept(EventCollision * e);
  void EventCmd(enum event_commands cmd);

  double battery_level(void) { return battery_.level(); }
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }
  int id(void) const { return id_; }
  std::string name(void) const {
    return "Robot" + std::to_string(id());}
    /*
     * the next funciton is to print the battey level on the screen and to
     * print the status of the user when the game is end
     * str_battery_level : return the battey level in string
     * setLowBatarryText : store teh ammount of the battery i lowbattary
     * setLoseGame : write the status of the User
     * loseGame return the staus of the user to print it on the window
     */
  std::string str_battery_level(void) const { return lowbattary; }
  void setLowBatarryText(std::string s) {
    lowbattary = s;
    if (losegame != "") {
      speed(0);
    }
    }
  std::string loseGame(void) const { return losegame; }
  void setLoseGame(std::string s) {losegame = s;}
  /*
   * this funcition is called in the arena to reduce the charge whent the robot
   * hits the obstecales
   */
  void reduceTheBattaryCharge(void) {battery_.reduceCharge();}
  /* to put the charge zero so the robot can not move even
   * if the user press the arrow keys.
   * we create one in the robot so we can call it in the arena by
   * robot_ -> setChargeZero()
   */
  void setChargeZero(void) {battery_.setChargeZero();}

 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  RobotBattery battery_;
  RobotMotionHandler motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  std::string lowbattary;
  std::string losegame = "";
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ROBOT_H_
