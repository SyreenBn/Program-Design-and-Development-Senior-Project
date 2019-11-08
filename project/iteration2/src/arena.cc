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
#include "src/player.h"
#include "src/robot.h"
#include "src/obstacle.h"
#include "src/event_collision.h"
#include "src/event_proximity.h"
#include "src/arena_params.h"
#include "src/recharge_station.h"
#include "src/home_base.h"
#include "src/event_recharge.h"
#include "src/sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/

/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
/*@bug I did not started the priority 3 yer */

Arena::Arena(const struct arena_params* const params) :
  x_dim_(params->x_dim), y_dim_(params->y_dim),
  /*
   * get the player information for the arena parameter
   */
// get the player information for the arena parameter
player_(new Player(&params->player)),
  n_players_(1),
  n_obstacles_(params->n_obstacles),
/*
 * get the number of the robot form the arena paramerter
 */
// get the number of the robot form the arena paramerter
  n_robots_(params->n_robots),
  recharge_station_(new RechargeStation(params->recharge_station.radius,
    params->recharge_station.pos,
    params->recharge_station.color)),
  /*
   * get the infomation of the home base from the aren parameter
   */
//  get the infomation of the home base from the aren parameter
  home_base_(new HomeBase(&params->home_base)),
  /*
   * create a Sensor sensor to to pass the event because the parent sensor class recive all type of event
   */
  /*  create a Sensor sensor to to pass the event
    because the parent sensor class recive all type of event */
  sensor_(),
  entities_(),
  mobile_entities_() {
   /**
   * @brief Informs we push the player to the entities_ vector and to the
   * mobile_entities_ vector, also we gave it an initial value of heading angle.
   * these statment to make the home base move and we did these statment with
   *the player too
   */
  player_->heading_angle(37);
  entities_.push_back(player_);
  mobile_entities_.push_back(player_);
  /**
   * @brief Informs we push the home base to the entities_ vector and to the
   * mobile_entities_ vector, also we gave it an initial value of heading angle.
   * these statment to make the home base move and we did these statment with
   *the player too
   */
  home_base_->heading_angle(49);
  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);
  /*
   * add the recharge station to the enitiies to be as an immobile enitiy
   */
  entities_.push_back(recharge_station_);
  /*
   * @brief Informs we push the robots to the entities_ vector, we use for loop because we havea  vecotr of robots
   */
  for (int j = 0; j < 5; ++j) {
         entities_.push_back(new Robot(&params->robot[j]));
  } /* for(i..) */

  /*
   * @brief Informs we push the obstecales to the entities_ vector, we use for loop because we havea  vecotr of robots
   */

  for (size_t i = 0; i <= n_obstacles_; ++i) {
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


/**
 * Register an observer
 * robot observer object to be removed
 */
void Arena::RegisterObservers(Robot * robot) {
  observer_entities.push_back(robot);
}

void Arena::Lose(void) {

  if (player_->battery_level() <=0) {
    player_ -> speed(0);
    /*
     * Tell the user that, he/she lost the game.
     */
    player_ -> setendGame("YOU LOST THE GAME, Restart Again");
    std::cout << "the player is out of charge\n";
  } else if ((player_->battery_level()> 0)
           &&(player_->battery_level() <= 4)) {
    /*
     * Reduce the speed of the player because the battey is low.
     */
  player_ -> speed(1);  //  because the charge less than  4
  std::cout << "please charge the player, the level of charge is less than 2";
   }

}

void Arena::UpdateEnt(void){
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */


}


/**
 * Romove an observer
 * robot observer object to be registered
 */
void Arena::RemoveSensor(Robot * robot) {
// find the observer
auto iterator = std::find(observer_entities.begin(),
                           observer_entities.end(), robot);
if (iterator != observer_entities.end()) {  //  observer found
  observer_entities.erase(iterator);  //  remove the observer
}
}

/*
* this funciton is searching about the robot to push it to mobile_entities_ vecotor and to return the robots vector because we need it for
* drawing the robot in grafic_viewer class
*/
std::vector<Robot*> Arena::robots(void) {
  std::vector<Robot*> robt;
  for (auto ent : entities_) {
    Robot* r = dynamic_cast<Robot*>(ent);
    if (r) {
      robt.push_back(r);
      mobile_entities_.push_back(r);
    }
  } /* for(ent..) */
  return robt;
} /* players() */

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> obstcls;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      obstcls.push_back(o);
    }
  } /* for(ent..) */
  return obstcls;
} /* players() */

void Arena::AdvanceTime(void) {
  std::cout << "Advancing simulation time by 1 timestep\n";
  /* the level of the battey is printed under the player name */
  player_ -> setLowBatarryText(std::to_string(player_ -> battery_level()));
  UpdateEntitiesTimestep();
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(void) {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   */
UpdateEnt();
  /*
   * Next, check if the player has run out of battery
   */
   Lose();

  EventCollision ec;
  CheckForEntityCollision(player_, recharge_station_,
    &ec, player_->collision_delta());
  if (ec.collided()) {
    EventRecharge er;
    player_-> Accept(&er);
    /*
     * Tell the user that, the battary is full right now.
     */
    player_ -> setLowBatarryText("battary is full");
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
  if (ent->get_pos().x+ ent->radius() >=  x_dim_ - 20) {
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
/*
* this fuction to check if there are any enieiy in the range of the robot
* it takes two parameters one is the robot and the other is any enitity
* the sensor will accept the event and in the sencoer calss the event will pass to the roobot class
*/
void Arena::CheckForEntityProximity(Robot*  ent1,
  ArenaEntity*  ent2,
  EventProximity * event) {
  /* Note: this assumes circular entities
   * find the x and y positon of each entitiy ot calculate the distance
   *@bug there is no aciton will taken because the implementaitn of the Accept fucntion in Sensor class does not work
   */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;

     if ((Distacne(ent1->get_pos(),ent2->get_pos()) > ent1->radius() +
                 ent2->radius() + ent1 -> RightProximitySensorRange())
      || (Distacne(ent1->get_pos(),ent2->get_pos()) > ent1->radius() +
                 ent2->radius() + ent1 -> LeftProximitySensorRange())) {
     event->proximitied(false);
     } else {
     event-> proximitied(true);
     sensor_->Accept(event);
}
}/* entities_have_proximated() */


/*
* this fuction to check if there are any roboot  in the range of the robot
* it takes two parameters one is the robot and the other is any enitity
* the sensor will accept the event and in the sencoer calss the event will pass to the roobot class
*/


void Arena::CheckForRobotvoidDistressCall(Robot*  ent1,
  Robot* ent2,
  EventDistressCall * event) {
  /* Note: this assumes circular entities
   * find the x and y positon of each entitiy ot calculate the distance
   *@bug there is no aciton will taken because the implementaitn of the Accept fucntion in Sensor class does not work
   */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;

     if (Distacne(ent1->get_pos(),ent2->get_pos()) > ent1->radius() +
                ent2->radius() +
                ent1 ->DistressSensorRange() +
                ent2 -> DistressSensorRange()) {
        event->distressed(false);
     } else {
       if (ent1 -> inDistress()) {
    event-> distressed(true);
        sensor_->Accept(event);
      } else if (ent1 -> inDistress()) {
        event-> distressed(true);
        sensor_->Accept(event);
    } else {
      event->distressed(false);
  }
}
}/* entities_have_distressed() */

/*
* this code is one of my trys of the prevece disgine which pass the entities and the event to the sensoer class
*/
// void Arena::CheckForEntityCollision( ArenaEntity*  ent1,
//    ArenaEntity*  ent2,
//   EventCollision * event,
//   double collision_delta) {
//   /* Note: this assumes circular entities */
//   double ent1_x = ent1->get_pos().x;
//   double ent1_y = ent1->get_pos().y;
//   double ent2_x = ent2->get_pos().x;
//   double ent2_y = ent2->get_pos().y;
//   double dist = std::sqrt(
//     std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
//   if (dist > ent1->radius() + ent2->radius() + collision_delta) {
//     event->collided(false);
//   } else {
//     // Populate the collision event.
//     // Collided is true
//     event-> collided(true);
//     printf ("& %f %f \n", event->point_of_contact().x,
//       event->point_of_contact().y);
//
//     EventCollision e;
//     printf ("&& %f %f \n", e.point_of_contact().x,  e.point_of_contact().y);
//     e.point_of_contact(event->point_of_contact());
//     e.angle_of_contact(event -> angle_of_contact());
//     printf ("&& %f %f \n", e.point_of_contact().x,  e.point_of_contact().y);
//
//     e.collided(true);
//     sensor_->Accept(e, ent1, ent2);
// }
// } /* entities_have_collided() */

double Arena::Distacne(Position ent1, Position ent2){
  double ent1_x = ent1.x;
  double ent1_y = ent1.y;
  double ent2_x = ent2.x;
  double ent2_y = ent2.y;
    double dist = std::sqrt(
    std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
  return dist;
}


void Arena::CheckForEntityCollision(const ArenaEntity* const ent1,
  const ArenaEntity* const ent2,
  EventCollision * event,
  double collision_delta) {
  /* Note: this assumes circular entities
   * find the x and y positon of each entitiy ot calculate the distance
   * this function do exactity as iteration one but I pass the event ot the sensor class
   *@bug there is no aciton will taken because the implementaitn of the Accept fucntion in Sensor class does not work
   */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;

    if (Distacne(ent1->get_pos(),ent2->get_pos()) > ent1->radius() + ent2->radius() + collision_delta) {
    event->collided(false);
  } else {
    event-> collided(true);
     //  ent1 -> entityType();
     second_entity_type = ent2->entityType();
     ent1_orignal_event_position = ent1->get_pos();
     ent2_orignal_event_position = ent2->get_pos();
     ent1_ = ent1->id_ent_num();
     sensor_->Accept(new EventCollision(ent1_,
       ent1_orignal_event_position,
       ent2_orignal_event_position,
       second_entity_type));
    //  sensor_->Accept(event);

    double newX = ((ent1_x * ent2-> radius()) + (ent2_x * ent1-> radius())) /
                                      (ent1-> radius() +  ent2-> radius());
    double newY = ((ent1_y * ent2-> radius()) + (ent2_y * ent1-> radius())) /
                                      (ent1-> radius() +  ent2-> radius());
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
  player_ -> EventCmd(arrow);
} /* player_have_accept_command() */

/*! Namespaces End */
NAMESPACE_END(csci3081);
