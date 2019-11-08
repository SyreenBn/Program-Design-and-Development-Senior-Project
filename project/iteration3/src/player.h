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
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/*
 * @brief this class to creast the playe rwhich is controlled by the user
 */

class Player : public ArenaMobileEntity {
 public:
  explicit Player(const struct player_params* const params);

      /* @brief ResetBattery reste the battary ot max charge
      *
      */
  void ResetBattery(void);

  /* @brief Reset reste the [layer ot the oringnal sitation
  *
  */
  void Reset(void);

  /* @brief HeadingAngleInc fun form base code
  *
  */
  void HeadingAngleInc(void) { heading_angle_ += angle_delta_; }

  /* @brief HeadingAngleDec fun form base code
  *
  */
  void HeadingAngleDec(void) { heading_angle_ -= angle_delta_; }

  /* @brief TimestepUpdate fun form base code
  *
  */
  void TimestepUpdate(unsigned int dt);

/* @brief accept the coloision event */
  void Accept(EventRecharge * e);

/* @brief to Accept EventCollision from the arena and pass it to the sensor */
  void Accept(EventCollision * e);

/* @brief accept the command event to chage the speed and th heading angle */
  void EventCmd(enum event_commands cmd);

/* @brief this funciton ot return the level of the battery */
  double battery_level(void) { return battery_.level(); }

  /* @brief to set and get the heading_angle of motion handler*/
  double heading_angle(void) const { return motion_handler_.heading_angle(); }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }

  /* @brief to set and get the speed of motion handler*/
  double speed(void) { return motion_handler_.speed(); }
  void speed(double sp) { motion_handler_.speed(sp); }

  /* @brief id is return -1 when the event clall this function in arena*/
  int id(void) const { return id_; }

  /* @brief name funcito is to print the nameof hte Player
   *
   */
  std::string name(void) const {
    return "Player" + std::to_string(id());}

    /*
     * @brief  the next funciton is to print the battey level on the screen and to
     * print the status of the user when the game is end
     * str_battery_level : return the battey level in string
     * setLowBatarryText : store teh ammount of the battery i lowbattary
     */
  std::string str_battery_level(void) const { return lowbattary; }
  void setLowBatarryText(std::string s) {
    lowbattary = s;
    if (losegame != "") {
      speed(0);
    }
    }

    /* @brief  setLoseGame : write the status of the User
    * loseGame return the staus of the user to print it on the window
    */
  std::string loseGame(void) const { return losegame; }


      /* @brief  setLoseGame : write the status of the User
      * loseGame return the staus of the user to print it on the window
      */
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
  const int& get_id(void) const { return id__; }

  /* @brief it is return the char of the enitity type to use it in the robot
   * when checking the senarios of collision
   */
  const char& entity_type(void) const {return entity_type_;}

  /* @brief this funciton to set the situation of the freezing
   * if the player inFreeze, it will ignore the
   * keypress events
   */
  bool inFreeze(void) {return frozen;}

  /* @brief this funciton to chech if the player inFreeze, it will ignore the
   * keypress events
   */
  void inFreeze(bool f) {frozen = f;}

 private:
  static unsigned int next_id_;
  int id_;
  double heading_angle_;
  double angle_delta_;
  PlayerBattery battery_;
  PlayerMotionHandler motion_handler_;
  PlayerMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  std::string lowbattary;
  std::string losegame = "";
  bool frozen = false;
  int id__ = -1;
  char entity_type_ = 'p';
  int time_ = 0;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_PLAYER_H_
