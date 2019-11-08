/**
 * @file player.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include "src/player.h"
#include "src/player_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Player::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct player_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
    params->pos, params->color),
  battery_(params->battery_max_charge),
  heading_angle_(0),
  angle_delta_(params->angle_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  id_(-1) {
  motion_handler_.heading_angle(270);
  motion_handler_.speed(5);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Player::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
  // Deplete battery as appropriate given distance and speed of movement
  battery_.Deplete(old_pos, get_pos(), dt);
} /* TimestepUpdate() */

void Player::Accept(__unused EventRecharge * e) {
  battery_.EventRecharge();
}

// Pass along a collision event (from arena) to the touch sensor.
// This method provides a framework in which sensors can get different
// types of information from different sources.
void Player::Accept(EventCollision * e) {
  /* @brief when the cclolsion happened it whii check if th eenitity is SuperBot
   * it yes the player will freezw and the timer will sit 100*/
  time_--;
  if (time_ == 0) {
    motion_handler_.speed(5);
    sensor_touch_.sensed(true);
    this->inFreeze(false);
    time_ = 100;
  }
  if (e -> type() == 'c') {
    if (entity_type_ == 'p' && ((e -> ent1() == 's') || (e -> ent2() == 's'))) {
      motion_handler_.speed(0);
      sensor_touch_.sensed(false);
      this->inFreeze(true);
      time_ = 100;
  } else {
    sensor_touch_.Accept(e);
  }
}
}

/* @brief  User input commands to change heading or speed */
void Player::EventCmd(enum event_commands cmd) {
  if ((battery_level() > 0) && (frozen == false)) {
  motion_handler_.AcceptCommand(cmd);
  } else {}
  } /* event_cmd() */


/* @brief  reset the player as it was in oringianl
 * reset motion home_base_motion_handler
 */
void Player::Reset(void) {
  battery_.Reset();
  motion_handler_.speed(5);
  sensor_touch_.Reset();
  setLoseGame("");
  losegame = "";
  motion_behavior_.UpdateOriginPosition(this);
  frozen = false;
} /* Reset() */

/* @brief  reset the batteruy to make full again
 * 
 */
void Player::ResetBattery(void) {
  battery_.Reset();
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
