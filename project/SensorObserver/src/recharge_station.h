/**
 * @file recharge_station.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_RECHARGE_STATION_H_
#define SRC_RECHARGE_STATION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/obstacle.h"
#include "src/color.h"
#include "src/sensor_entity_type.h"
#include "src/entity_type.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class RechargeStation: public Obstacle {
 public:
  RechargeStation(double radius, const Position& pos,
                  const Color& color) :
      Obstacle(radius, pos, color) {}
  std::string name(void) const {
    return "Recharge Station";
  }
/*
* this funcitoin is to return the private enum varialbe
*/
//  enum entity_type entityType(void) {return entity_type_;}
  const int& get_id(void) const { return id__; }
  const char& entity_type(void) const {return entity_type_;}


 private:
 /*
* this variable to check the enitiy when the event is passed ot the paernt sensor class
*/
  //enum entity_type entity_type_ = kRechargeStation;
  int id__ = -1;
  char entity_type_ = 'c';
};

NAMESPACE_END(csci3081);

#endif  // SRC_RECHARGE_STATION_H_
