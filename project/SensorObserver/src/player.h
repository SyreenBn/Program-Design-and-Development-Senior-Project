/**
 * @file player.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_PLAYER_H_
#define SRC_PLAYER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/player_motion_handler.h"
#include "src/player_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/player_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/sensor_entity_type.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Player : public ArenaMobileEntity {
 public:
  explicit Player(const struct player_params* const params);

  void ResetBattery(void);
  void Reset(void);
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }
  void TimestepUpdate(unsigned int dt);
/* accept the coloision event */
  void Accept(EventRecharge * e);
/* accept the echarge event ot recharge the battery */
  void Accept(EventCollision * e);
/* accept the command event to chage the speed and th heading angle */
  void EventCmd(enum event_commands cmd);
  double battery_level(void) { return battery_.level(); }
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }
  int id(void) const { return id_; }
  std::string name(void) const {
    return "Player" + std::to_string(id());}
  const std::string& namei(void) const {
    return "Player";}
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
   * this funcition is called in the arena to reduce the charge whent the player
   * hits the obstecales
   */
  void reduceTheBattaryCharge(void) {battery_.reduceCharge();}
  /* to put the charge zero so the player can not move even
   * if the user press the arrow keys.
   * we create one in the player so we can call it in the arena by
   * player -> setChargeZero()
   */
  void setChargeZero(void) {battery_.setChargeZero();}

/*
* this funcitoin is to return the private enum varialbe
*/
  //const enum entity_type entityType(void) const {return entity_type_;}
  const int& get_id(void) const { return id__; }
  const char& entity_type(void) const {return entity_type_;}
  bool inFreeze(void){return frozen;}
  void inFreeze(bool f){frozen = f;}



 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  PlayerBattery battery_;
  PlayerMotionHandler motion_handler_;
  PlayerMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  //enum entity_type entity_type_ = kPlayer;
  std::string lowbattary;
  std::string losegame = "";
  bool frozen = false;
  int id__ = -1;
  char entity_type_ = 'p';
  int time_ = 100;

};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_PLAYER_H_
