/**
 * @file obstacle.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/obstacle.h"
#include "src/color.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Obstacle::next_id_ = 4;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Obstacle::Obstacle(double radius, const Position& pos,
                                   const Color& color) :
    ArenaImmobileEntity(radius, pos, color),
    id_(-1) {
  id_ = next_id_++;
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
