/**
 * @file player_arena.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_H_
#define SRC_ARENA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include <string>

#include "src/event_keypress.h"
#include "src/event_collision.h"
#include "src/event_proximity.h"
#include "src/player.h"
#include "src/robot.h"
#include "src/sensor.h"
#include "src/home_base.h"
#include "src/recharge_station.h"
#include "src/entity_type.h"
#include "src/subject_entity_type.h"
#include "src/subject_distress.h"
#include "src/subject_collision.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct arena_params;

/**
 * @brief The main class for the simulation of a 2D world with many players running
 * around.
 *
 * PlayerViewer or Tests call \ref set_time and \ref advance_time to control the
 * simulation and use the get*() functions to read out the current state of the
 * simulation (i.e., the current positions and orientations of players and
 * obstacles).
 *
 *  For now, PlayerArena is hard coded to run a simulation of two players running
 *  around in a circle.  You can see their sensors, but they don't yet respond
 *  to each other or to obstacles.
 */
class Arena {
 public:
  explicit Arena(const struct arena_params * const params);
  ~Arena(void);

   void RegisterObservers(Robot * robot);
   void RemoveSensor(Robot * robot);
   void ChangeOfState(EventBaseClass * event_);
   void SendNotification(EventBaseClass * event_);

  /**
   * @brief Advance the simulation by a single step.
   */
  void AdvanceTime(void);

  /**
  * @brief Handle the key press passed along by the viewer.
  *
  * @param[in] an event holding the key press.
  *
  */
  void Accept(EventKeypress * e);

  // Reset all in the arena
  void Reset(void);

  /*
   * @brief Get the # of players in the arena.
   */
  unsigned int n_players(void) { return n_players_; }

  /*
   * @brief Get # of obstacles in the arena.
   */
  unsigned int n_obstacles(void) { return n_obstacles_; }

  /*
   * @brief Get # of robots in the arena.
   */
  unsigned int n_robots(void) { return n_robots_; }


  /**
   * @brief Get a list of all obstacles (i.e. non-mobile entities in the arena).
   */
  std::vector<class Obstacle*> obstacles(void);

/**
   * @brief Get a list of all robots (i.e. mobile entities in the arena).
   */
  std::vector<class Robot*> robots(void);


  /**
   * @brief Get the list of all mobile entities in the arena.
   */
  std::vector<class ArenaMobileEntity*> mobile_entities(void)
    { return mobile_entities_; }

/* this senor to accept all type of event and pass it ot its entities */
  Sensor* sensor_;
/* return the palyer to draw in graphic calss */
  Player* player(void) const { return player_; }

/* return the home base to draw in graphic calss */
  HomeBase* home_base(void) const { return home_base_; }

/* return the recharge station to draw in graphic calss */
RechargeStation* recharge_station(void) const { return recharge_station_; }


 private:
  /**
   * @brief Determine if two entities have collided in the arena. Collision is
   * defined as the difference between the extents of the two entities being less
   * than a run-time parameter.
   *
   * @param ent1 Entity #1.
   * @param ent2 Entity #2.
   * @param pointer to a collision event
   *
   * Collision Event is populated appropriately.
   */
  // this function is for the old design
  // void CheckForEntityCollision( ArenaEntity* ent1,
  //   ArenaEntity* ent2,
  //   EventCollision * ec,
  //   double collision_delta);
  void CheckForEntityCollision(const class ArenaEntity* const ent1,
   const class ArenaEntity* const ent2,
   EventCollision * ec,
   double collision_delta);

  /**
   * @brief Determine if any robots distressed in the arena. disturess is
   * defined as the difference between the distacne of the two robots and the range of the disstress sensor being less
   * than a run-time parameter.
   *
   * @param ent1 Robot #1.
   * @param ent2 Robot #2.
   * @param pointer to a distress event
   *
   * Distress Event is populated appropriately.
   */
  void CheckForRobotvoidDistressCall(Robot*  ent1,
    Robot* ent2,
    EventDistressCall * event);

/**
   * @brief Determine if any entity in the range of robot to proximated in the arena. proximity is
   * defined as the difference between the distacne of the two robots and the rangeo fthe porximity sensor being less
   * than a run-time parameter.
   *
   * @param ent1 Robot #1.
   * @param ent2 Robot #2.
   * @param pointer to a proximity event
   *
   * Proximity Event is populated appropriately.
   */
  void CheckForEntityProximity(Robot*  ent1,
     ArenaEntity*  ent2,
     EventProximity * event);

  /**
   * @brief Determine if a particular entity is gone out of the boundaries of
   * the simulation.
   *
   * @param ent The entity to check.
   * @param pointer to a collision event.
   *
   * Collision event is populated appropriately.
   */
  void CheckForEntityOutOfBounds(const class ArenaMobileEntity* const ent,
    EventCollision * ec);
  void CheckForEntityOutOfBounds(Robot * ent,
    EventProximity * event);

  /**
   * @brief Update all entities for a single timestep
   */
  void UpdateEntitiesTimestep(void);

  // Under certain circumstance, the compiler requires that the copy
  // constructor is not defined. This is deleting the default copy const.
  Arena& operator=(const Arena& other) = delete;
  Arena(const Arena& other) = delete;

  // Dimensions of graphics window inside which players must operate
  double x_dim_;
  double y_dim_;
  unsigned int n_players_;
  unsigned int n_obstacles_;
  unsigned int n_robots_;  //  to get the number of the robot from arean

  enum entity_type second_entity_type;
  enum entity_type first_entity_type;
  Position ent1_orignal_event_position;
  Position ent2_orignal_event_position;
  int ent1_;
  double ent1_raduis;
  double ent2_raduis;
  // Entities populating the arena
  Player* player_;
  RechargeStation * recharge_station_;
  HomeBase * home_base_;
  int MaxRang = 0;
/* this vecotor is to register an observer */
  std::vector<class Robot*> observer_entities;
  std::vector<class ArenaEntity*> entities_;
  std::vector<class ArenaMobileEntity*> mobile_entities_;
  SubjectEntityType * SubjectEntityType_;
  SubjectDistress * SubjectDistress_;
  SubjectCollision * SubjectCollision_;
  SubjectBase * subject;
  std::vector<Robot*> robt_;
  bool win_the_game;
  bool lose_the_game;

};


/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_ARENA_H_
