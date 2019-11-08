/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

/*******************************************************************************
 * Macros
 ******************************************************************************/
/*! The define of Namespaces Begin */
// #define NAMESPACE_BEGIN(name) namespace name {
// /*! The define of Namespaces End */
// #define NAMESPACE_END(name) }

/** Namespaces Begin */
NAMESPACE_BEGIN(csci3081);



/* This should be placed in front of any variable defined but not used to
// satisfy the compiler - otherwise a warning is given.
    The define of non used attribute 
//  #define __unused __attribute__((unused))
*/
struct Position {
Position(void) : x(0), y(0) { }
Position(int in_x, int in_y) : x(in_x), y(in_y) { }
  int x;
  int y;
};

/*! Namespaces End */
NAMESPACE_END(csci3081);

#endif  // SRC_POSITION_H_
