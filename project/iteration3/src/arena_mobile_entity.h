/**
 * @file mobile_arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "src/arena_entity.h"
#include "src/event_base_class.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/color.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /** @brief arena_mobile_entity_params is to stor the information of the
   * mobile enititis such as player homebase and robots and superbot
   * it is responsible of updating the motion handler of all these enitities
   */

class ArenaMobileEntity : public ArenaEntity {
 public:
/*******************************************************************************
 * Constructor
 ******************************************************************************/
  ArenaMobileEntity(double radius, double collision_delta,
                    const Position& pos, const Color& color) :
      ArenaEntity(radius, pos, color),
      collision_delta_(collision_delta) {}

/*******************************************************************************
 * Member Function
 ******************************************************************************/
/** check the mobility characteristic */
  bool is_mobile(void) { return true; }

  /** this function is to get the heading_angle of the enitity */
  virtual double heading_angle(void) const = 0;

  /** this function is to set the heading_angle of the enitity */
  virtual void heading_angle(double heading_angle) = 0;

  /** this function is to get the speed of the enitity */
  virtual double speed(void) = 0;

  /** this function is to set the speed of the enitity */
  virtual void speed(double sp) = 0;

  /** this function is to get the collision_delta of the enitity */
  double collision_delta(void) const { return collision_delta_; }

  /** this function is TimestepUpdate to update the movment of the enitity */
  void TimestepUpdate(uint dt);

  /** this function is Accept the EventCollision to call the senor touch to take
    *  the right angle
    */
  virtual void Accept(EventCollision * e) = 0;

  /** this function is Accept the EventRecharge to refill the batttery of
    * the player and call the senor touch to take
    *  the right angle, but all enitity exept the player is just call the
    * senor touch to take
    */
  virtual void Accept(EventRecharge * e) = 0;

  /**
   * @brief this funciton get_id ot set the id of the enitity. all enieitiues will return -1
   * exept the robot it will return the number of the robot.
   * this function for observers pattren to check if this is the enitity which suppose to
   * recive the aciton or not
   */
  virtual const int& get_id(void) const = 0;



 private:
  double collision_delta_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_MOBILE_ENTITY_H_
