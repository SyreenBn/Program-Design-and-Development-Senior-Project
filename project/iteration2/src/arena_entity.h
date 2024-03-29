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

/* Namespaces Begin */
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
  virtual std::string name(void) const = 0;
  const std::string namei(void) const {}
  const int id_ent_num(void) const {}
  void set_pos(const Position& pos) { pos_ = pos; }
  const Position& get_pos(void) const { return pos_; }
  const Color& color(void) const { return color_; }
  void color(const Color& color) { color_ = color; }
  virtual bool is_mobile(void) = 0;
  double radius(void) const { return radius_; }
  enum entity_type entityType(void) {return entity_type_; }
  void moving_around(bool ma) { moving_around_ = ma;}
  bool moving_around(void) {return moving_around_;}
  virtual void Accept(EventCollision event) {}
  virtual void Accept(EventBaseClass * event ) {}
  const enum entity_type entityType(void) const {}

 private:
  double radius_;
  Position pos_;
  Color color_;
  bool moving_around_;
  enum entity_type entity_type_;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_ENTITY_H_
