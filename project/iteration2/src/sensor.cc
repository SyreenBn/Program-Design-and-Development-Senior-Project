/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor.h"
#include "src/arena_entity.h"
#include "src/robot.h"
#include "src/arena.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);
class Arena;
/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Sensor::Sensor() :
  sensed_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}

// it is on of my tries of the old desinge

/*
 void Sensor::Accept (EventBaseClass event) {
    //find the distance between the entities to decide which entity will accept the event and which one will bounce
    double ent1_x = ent1->get_pos().x;
    double ent1_y = ent1->get_pos().y;
    double ent2_x = ent2->get_pos().x;
    double ent2_y = ent2->get_pos().y;
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
    event.angle_of_contact(angle*(180/PI));
    // Point of contact is point along perimeter of ent1
    // printf ("#################################################################");
    // printf ("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ %f", &event.point_of_contact().x);
    event.point_of_contact(Position(newX, newY));
    ent1 -> Accept(&event);
    ent2 -> Accept(&event);

    if ( (((ent1 -> entityType()) == kRobot) && (ent2 -> entityType() == kRobot)) ) {
  //check if they send distress call
    } else if ( ((ent2 -> entityType() == kRobot) && (ent1 -> entityType() == kPlayer)) ){
    //  dynamic_cast<Robot*>(ent2) -> sensor_touch(false);

      // printf ("########################################################################################################################################################################### ");
      // printf ("Hi $$$$$$$$$$$$$$$$$$$$$ %B",dynamic_cast<Robot*>(ent2) -> sensor_touch());
    } else if (((ent1 -> entityType() == kRobot) && (ent2 -> entityType() == kPlayer)) ) {
      ent1 -> moving_around(false);

    } else if ( ((ent1 -> entityType() == kRobot) && (ent2 -> entityType() == kHomeBase)) || ((ent2 -> entityType() == kRobot) && (ent1 -> entityType() == kHomeBase)) ){

    } else if ( ((ent1 -> entityType() == kRobot) && (ent2 -> entityType() == kObstacle)) || ((ent2 -> entityType() == kRobot) && (ent1 -> entityType() == kObstacle)) ){

    } else if ( ((ent1 -> entityType() == kRobot) && (ent2 -> entityType() == kSuperBot)) || ((ent2 -> entityType() == kRobot) && (ent1 -> entityType() == kSuperBot)) ){
      // check if freeze and unfreeze
    } else if ( ((ent1 -> entityType() == kSuperBot) && (ent2 -> entityType() == kPlayer)) || ((ent2 -> entityType() == kSuperBot) && (ent1 -> entityType() == kPlayer)) ){

    } else if ( ((ent1 -> entityType() == kPlayer) && (ent2 -> entityType() == kRechargeStation)) || ((ent2 -> entityType() == kPlayer) && (ent1 -> entityType() == kRechargeStation)) ){

    } else {


    }
}
*/
/*
* gthis funciton is accept all types of event and then pass each event to the appropieat enitity
*/
void Sensor::Accept(EventBaseClass * event) {
printf("################################################################## ");
}
/*
// this is another try of the old design
// void Sensor::Accept (EventBaseClass * event,
//              class ArenaEntity* const ent, double requied_distance) {
//               //  double an;
//               //  if (ent->get_pos().x+ ent->radius() + requied_distance >= x_dim_) {
//               //    // Right Wall
//               //    event->collided(true);
//               //    event->point_of_contact(Position(x_dim_, ent->get_pos().y));
//               //    an = ent->heading_angle() - 180;
//               //    event->angle_of_contact(an);
//               //  } else if (ent->get_pos().x - ent->radius() - requied_distance <= 0) {
//               //    // Left Wall
//               //    event->collided(true);
//               //    event->point_of_contact(Position(0, ent->get_pos().y));
//               //    an = ent->heading_angle() - 270;
//               //    event->angle_of_contact(an);
//               //  } else if (ent->get_pos().y+ ent->radius() + requied_distance >= y_dim_) {
//               //    // Bottom Wall
//               //    event->collided(true);
//               //    event->point_of_contact(Position(ent->get_pos().x, y_dim_));
//               //    event->angle_of_contact(ent->heading_angle());
//               //  } else if (ent->get_pos().y - ent->radius() - requied_distance <= 0) {
//               //    // Top Wall
//               //    event->collided(true);
//               //    event->point_of_contact(Position(0, y_dim_));
//               //    event->angle_of_contact(ent->heading_angle());
//               //  } else {
//               //    event->collided(false);
//               //  }
// }
//
*/
/*! Namespaces End */
NAMESPACE_END(csci3081);
