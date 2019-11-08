/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <algorithm>

#include "src/arena.h"
#include "src/robot.h"
#include "src/obstacle.h"
#include "src/event_collision.h"
#include "src/arena_params.h"
#include "src/recharge_station.h"
#include "src/home_base.h"
#include "src/event_recharge.h"




/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params* const params) :
  x_dim_(params->x_dim), y_dim_(params->y_dim),
  robot_(new Robot(&params->robot)),
  n_robots_(1),
  n_obstacles_(params->n_obstacles),
  recharge_station_(new RechargeStation(params->recharge_station.radius,
    params->recharge_station.pos,
    params->recharge_station.color)),
  home_base_(new HomeBase(&params->home_base)),
  entities_(),
  mobile_entities_() {
  robot_->heading_angle(37);
  entities_.push_back(robot_);
  mobile_entities_.push_back(robot_);

  entities_.push_back(recharge_station_);

  /**
   * @brief Informs we push the home base to the entities_ vector and to the
   * mobile_entities_ vector, also we gave it an initial value of heading angle.
   * these statment to make the home base move and we did these statment with
   *the robot too
   */
  home_base_->heading_angle(49);
  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);


  for (size_t i = 0; i < n_obstacles_; ++i) {
    entities_.push_back(new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color));
  } /* for(i..) */
}

Arena::~Arena(void) {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::Reset(void) {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> res;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */

void Arena::AdvanceTime(void) {
  std::cout << "Advancing simulation time by 1 timestep\n";
  /* the level of the battey is printed under the robot name */
  robot_ -> setLowBatarryText(std::to_string(robot_ -> battery_level()));
  UpdateEntitiesTimestep();
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(void) {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   */
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */

  /*
   * Next, check if the robot has run out of battery
   */
    if (robot_->battery_level() <=0) {
      robot_ -> speed(0);
      /*
       * Tell the user that, he/she lost the game.
       */
      robot_ -> setLoseGame("YOU LOST THE GAME, Restart Again");
      std::cout << "the robot is out of charge\n";
    } else if ((robot_->battery_level()> 0) &&(robot_->battery_level() <= 4)) {
      /*
       * Reduce the speed of the robot because the battey is low.
       */
    robot_ -> speed(1);
    std::cout << "please charge the robot, the level of charge is less than 2";
     } else { }
  /*
   * Next, check if the robot has collided with the recharge station or the home
   * base. These need to be before the general collisions, which can move the
   * robot away from these "obstacles" before the "collisions" have been
   * properly processed.
   */

  EventCollision ec;

  CheckForEntityCollision(robot_, home_base_, &ec, robot_->collision_delta());
  if (ec.collided()) {
    /*
     * Tell the user that, he/she won the game.
     */
    robot_ -> setLoseGame("WOW, YOU WON THE GAME");
    /*
     * to make the robot stop even if the user press the arrow keys
     */
    // robot_ -> setChargeZero();
    /*
     * The speed of the robot and the home base is 0 because the user is won the
     * game and the game is end.
     */
    robot_ -> speed(0);
    home_base_ -> speed(0);
  }

  CheckForEntityCollision(robot_, recharge_station_,
    &ec, robot_->collision_delta());
  if (ec.collided()) {
    EventRecharge er;
    robot_->Accept(&er);
    /*
     * Tell the user that, the battary is full right now.
     */
    robot_ -> setLowBatarryText("battary is full");
  }

  /*
   * Finally, some pairs of entities may now be close enough to be considered
   * colliding, send collision events as necessary.
   *
   * When something collides with an immobile entity, the immobile entity does
   * not move (duh), so no need to send it a collision event.
   */
  for (auto ent : mobile_entities_) {
    // Check if it is out of bounds. If so, use that as point of contact.
    assert(ent->is_mobile());
    CheckForEntityOutOfBounds(ent, &ec);

    // If not at wall, check if colliding with any other entities (not itself)
    if (!ec.collided()) {
      for (size_t i = 0; i < entities_.size(); ++i) {
        if (entities_[i] == ent) {
          continue;
        }
        CheckForEntityCollision(ent, entities_[i], &ec, ent->collision_delta());
        if (ec.collided()) {
          break;
        }
      } /* for(i..) */
    } /* else */
    ent->Accept(&ec);
  } /* for(ent..) */
} /* UpdateEntities() */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity * const ent,
  EventCollision * event) {
  double an;
  if (ent->get_pos().x+ ent->radius() >= x_dim_) {
    // Right Wall
    event->collided(true);
    event->point_of_contact(Position(x_dim_, ent->get_pos().y));
    an = ent->heading_angle() - 180;
    event->angle_of_contact(an);
  } else if (ent->get_pos().x- ent->radius() <= 0) {
    // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y));
    an = ent->heading_angle() - 270;
    event->angle_of_contact(an);
  } else if (ent->get_pos().y+ ent->radius() >= y_dim_) {
    // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, y_dim_));
    event->angle_of_contact(ent->heading_angle());
  } else if (ent->get_pos().y - ent->radius() <= 0) {
    // Top Wall
    event->collided(true);
    event->point_of_contact(Position(0, y_dim_));
    event->angle_of_contact(ent->heading_angle());
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityCollision(const ArenaEntity* const ent1,
  const ArenaEntity* const ent2,
  EventCollision * event,
  double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
    double dist = std::sqrt(
    std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
    /*
     * one of the tries of the angle of contact when the mobile entity hit the
     * other entity.
     * double angle = (((atan2(ent2_y - ent1_y, ent2_x - ent1_x))*180)/3.14159);
     */
    if (dist > ent1->radius() + ent2->radius() + collision_delta) {
    event->collided(false);
  } else {
    // Populate the collision event.
    // Collided is true
    event-> collided(true);
    /*
     * calucalting the new position
     */
    double newX = ((ent1_x * ent2-> radius()) + (ent2_x * ent1-> radius())) /
                                      (ent1-> radius() +  ent2-> radius());
    double newY = ((ent1_y * ent2-> radius()) + (ent2_y * ent1-> radius())) /
                                      (ent1-> radius() +  ent2-> radius());
    /*
     * calucalting the new angle
     */
    double PI = 3.14159;
    double angle = 0.0;
    if (ent1_x - ent2_x == 0) {
      angle = PI + (ent1_y - ent2_y)* PI/2;
    } else if (ent1_x > ent2_x) {
      angle = atan((ent1_y - ent2_y)/(ent2_x - ent1_x));
    } else {
      angle = atan((ent1_y - ent2_y)/(ent2_x - ent1_x)) + PI;
    }

    // Angle of contact is angle to that point of contact
    event-> angle_of_contact(angle*(180/PI));
    // Point of contact is point along perimeter of ent1
    event->point_of_contact(Position(newX, newY));
    /*
     * when the robot hits the other obstacles, the charge will reduce and the
     * speed will slow down.
     */
    robot_ -> reduceTheBattaryCharge();
    robot_ -> speed(2);

/*
 * This one of the way to avoid bouncing in two position, I treid to do this
 * because the home base is allways go to another pos and then back to continue
 * its way
 * check the bouncing just in two possition
    ((ent1_x + ent1 -> radius() +  ent2 -> radius() > ent2_x) &&
    (ent1_x < ent2_x + ent1 -> radius() + ent2 -> radius() ) &&
    (ent1_y + ent1 -> radius() +  ent2 -> radius() > ent2_y) &&
    (ent1_y < ent2_y + ent1 -> radius() + ent2 -> radius() ) ) {
*/
}
} /* entities_have_collided() */

  void Arena::Accept(__unused EventKeypress * e) {
    /* This function will recieve the keypress
     * then, we will call the get_key function to get the cmd of the keypress
     * Next, we will call the get_key_cmd function to recognize what this cmd do
     * finally, we will call the EventCmd passing the type of the action of cmd
     * key we need and in this function the action will be done.
     */
  int cmd = e -> get_key();
  enum event_commands arrow = e-> get_key_cmd(cmd);
  robot_ -> EventCmd(arrow);
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
