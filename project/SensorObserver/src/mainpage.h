#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage CSCI3081 player Simulator Project
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 *
 * \section intro_sec Introduction
 * (Robot Simulator)
 * The robot simulator is a video game. There are eight entities, some of them
 * are mobile while the other are immobile. Six of these entities are immobile
 * and they divide into two categories which are obstacles and recharge station.
 * The number of the obstacles are five and they act as solid walls. The last
 * immobile entity is the recharge station and its job recharges the robot
 * battery. The other category is the mobile entities and there are two of them.
 * They are a robot and a home base, and they are moving around. However, there
 * are some difference between these two entities. The home base is moving
 * around by itself and nobody effect on its move. Also, the heading angle of
 * the home base is changing randomly.
 * The other one is the robot. It could be controlled by a user by using the
 * arrow keys. The right and left arrow are to change the robot head angle while
 * the up and down are to change the speed. The robot has a sensor to calculate
 * the angle of contact during the movement. Moreover, the robot has a battery
 * and it is depleting as the robot move. The depletion process depends on the
 * speed and the distance. The battery level is printed on the screen under the
 * robot.  If the charge approaches 4.00, the speed of the robot will be 1 until
 * the user recharges the robot again. Furthermore, if the charge
 * approaches 0.00, that means the user loses the game and
 * “YOU LOST THE GAME, Restart Again” will print on the screen under the battery
 * level. So, the user needs to press restart button to play the game again.
 * To win the game, the user must hit the home base being out of charge.
 * Furthermore, the user should avoid hitting the obstacles because if the robot
 * bumps into obstacles, the speed will slow down, and the battery will deplete.
 * If the user wins the game, “WOW, YOU WON THE GAME” will print on the screen
 * under the robot and the home base and robot will stop moving. If the user
 * wants to stop playing the game for a while, he/she could press on “Pause”
 * button and the game will stop. And, if he/she press “Play” button again,
 * the same game will continue.
 * All drawing action is done in graphics_arena_viewer class while the color is
 * done in color class. However, the arena class is responsible to check if the
 * collision with the other entities happened to change the heading angle of the
 * mobile entity or to win if the collision happened with the home base.
 *
 *
 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */
#endif  // SRC_MAINPAGE_H_
