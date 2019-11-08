/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_H_
#define SRC_ARENA_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include <string>
#include "src/common.h"
#include "src/color.h"
#include "src/entity_type.h"
#include "src/event_collision.h"
#include "src/event_base_class.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);



/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A base class representing an entity within the arena. All entities
 * within the arena know how to :
 *
 * 1. Update themselves each timestep (i.e. in accordance with current velocity
 *    and position).
 * 2. Reset themselves to a newly constructed state. This is so the user can
 *    click the reset button after completing a game and have things work as
 *    expected.
 *
 * Note that not all classes need to be able to do these two things.
 */

class ArenaEntity {
 public:
  ArenaEntity(double radius, const Position& pos,
              const Color& color) :
      radius_(radius), pos_(pos), color_(color) {}
  virtual ~ArenaEntity(void) {}

  /**
   * @brief Perform whatever updates are needed for a particular entity after 1
   * timestep (updating position, changing color, etc.).
   */
  virtual void TimestepUpdate(__unused uint dt) {}

  /**
   * @brief Reset the entity to its newly constructed state.
   */
  virtual void Reset(void) {}
  /**
   * @brief this function name to write the name of the enitity on the circle to make
   * the enitity clear fo rthe player
   */
  virtual std::string name(void) const = 0;
  /**
   * @brief this funciton set_pos ot set teh position of the enitity
   */
  void set_pos(const Position& pos) { pos_ = pos; }
  /**
   * @brief this funciton get_pos ot get the position of the enitity
   */
  const Position& get_pos(void) const { return pos_; }
  /**
   * @brief this funciton color ot get teh color of the enitity
   */
  const Color& color(void) const { return color_; }
  /**
   * @brief this funciton color ot set teh color of the enitity
   */
  void color(const Color& color) { color_ = color; }
  /**
   * @brief this funciton is_mobile ot check the mobility characterestic of the enitity
   */
  virtual bool is_mobile(void) = 0;
  /**
   * @brief this funciton radius ot get teh raduis of the enitity
   */
  double radius(void) const { return radius_; }
  /**
   * @brief this funciton radius ot set teh raduis of the enitity
   */
  void radius(double r) { radius_ = r; }
  /**
   * @brief this funciton get_id ot set the id of the enitity. all enieitiues will return -1
   * exept the robot it will return the number of the robot.
   * this function for observers pattren to check if this is the enitity which suppose to
   * recive the aciton or not
   */
  virtual const int& get_id(void) const = 0;
  /**
   * @brief entity_type carry the char of the enitity name to make checking
   * the senarios easier to check
   */
  virtual const char& entity_type(void) const = 0;

 private:
  double radius_;
  Position pos_;
  Color color_;
  bool moving_around_;
  int id_ = -1;
};

/** Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_H_
