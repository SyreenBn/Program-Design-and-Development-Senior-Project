/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include "src/robot_motion_behavior.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);


/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params* const params) :
  ArenaMobileEntity(params->radius, params->collision_delta,
    params->pos, params->color),
  heading_angle_(10),
  angle_delta_(params->angle_delta),
  motion_handler_(),
  motion_behavior_(),
  sensor_touch_(),
  sensor_distress_(),
  id_(-1) {
  // subject = s;
  // subject.RegisterObservers(this);
  motion_handler_.heading_angle(60);
  motion_handler_.speed(3);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(uint dt) {
  if (moving_around_) {
  Position old_pos = get_pos();
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_, right_sensor_proximity_,
                                 sensor_distress_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
}
} /* TimestepUpdate() */

/*
* @brief Pass along a proximity event (from sensor) to the left_sensor_proximity and right_sensor_proximity.
* This method provides a framework in which sensors can get different
* types of information from different sources.
*/
void Robot::Accept(EventProximity * e) {
left_sensor_proximity_.Accept(e);
right_sensor_proximity_.Accept(e);
}

/*
* @brief Pass along a base event (from sensor) to the the requirmed sensor
* This method provides a framework in which sensors can get different
* types of information and events from different sources.
*/
void Robot::Accept(EventBaseClass * e) {
  if (entity_type_ == 'r' && ((e -> entity_id1() == this->get_id()))) {
    if (e -> type() == 'c') {
      if (entity_type_ == 'r' &&
        ((e -> ent1() == 'p') || (e -> ent2() == 'p'))) {
        motion_handler_.speed(0);
        sensor_touch_.sensed(false);
        sensor_distress_.sensed(true);
        motion_handler_.speed(0);
    } else if (entity_type_ == 'r' &&
              ((e -> ent1() == 'h') || (e -> ent2() == 'h'))) {
        this->radius(25);
        this->color(csci3081::Color(255, 153, 0, 255));
        this -> inSuperBot(true);
        sensor_touch_.Accept(e);
        entity_type_ = 's';
        name_ = "SuperBot";
    } else if (entity_type_ == 'r' && (e -> ent2() == 'r')) {
      motion_handler_.speed(3);
      sensor_touch_.sensed(true);
      sensor_distress_.sensed(false);
      sensor_touch_.Accept(e);
    } else if (entity_type_ == 's' &&
              ((e -> ent1() == 'w') || (e -> ent2() == 'w'))) {
        sensor_touch_.Accept(e);
    } else {
      sensor_touch_.Accept(e);
    }
} else if (e -> type() == 'x') {
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^6\n");
      right_sensor_proximity_.Accept(e);
}  else if (e -> type() == 'd') {
printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^6\n");
      sensor_distress_.Accept(e);
}
}
}

/*
* @brief Pass along a distress event (from sensor) to the sensor_distress
* This method provides a framework in which sensors can get different
* types of information from different sources.
*/
void Robot::Accept(EventDistressCall * e) {
sensor_distress_.Accept(e);
}

/* this event does not use but I add because it is virtual
 *in the arena eneitiy class
 */
void Robot::Accept(EventRecharge * e) {
  Accept(e);
}

/*
* @brief resent the robot to the orignal situaiton
* reset the sensor
* reset the color and the size
* reset the type and name
*/
void Robot::Reset(void) {
  motion_handler_.Reset();
  motion_behavior_.UpdateOriginPosition(this, init_x, init_y);
  sensor_touch_.Reset();
  sensor_distress_.Reset();
  right_sensor_proximity_.Reset();
  this->color(csci3081::Color(243, 98, 115, 255));
  this->radius(20);
  entity_type_ = 'r';
  std::cout << "Robot reset successful\n";
  name_ = "Robot";
} /* Reset() */


/*! Namespaces End */
NAMESPACE_END(csci3081);
