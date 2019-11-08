/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include<assert.h>
#include <fstream>      // std::ifstream
#include <string>
#include <iostream>
#include <iomanip>


#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"
#include "src/color.h"
#include "src/common.h"
#include "src/obstacle.h"

// using namespace std;


/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
 /** @brief
   * this funciton read the inforamtion from the txt file and pass the
   * information to arena_params
   */
int main(int argc, char * argv[]) {
csci3081::InitGraphics();
std::ifstream config;
std::string line;
config.open(argv[1]);
assert(config.is_open());
csci3081::arena_params aparams;
csci3081::robot_params rparams[8];
aparams.n_obstacles = 6;
aparams.n_robots = 6;
aparams.x_dim = 1024;
aparams.y_dim = 768;
char command[100];
int counter = 0;
int obt_counter = 0;   //  to check the number of the obseticales
int rbt_counter = 0;   //  to check the number of the robot

while(getline(config, line)) {
if (line[0] == '#') continue;
sscanf(line.c_str(), "%s ", command);
std::string cmd = command;
/* thhis if statment ot draw the "Obstacle" and
 * passing the infomatin ot the aren parameters
 */
if (cmd == "Obstacle") {
counter++;
float x, y, rad;
int r, g, b;
sscanf(line.c_str(), "%s ", command);
sscanf(line.c_str(), "Obstacle %f %f %f %d %d %d", &x, &y, &rad, &r, &g, &b);
std::cout << x << y << rad << r << g << b << std::endl;
//  Color color = new Color(r, g, b, 255);
if (obt_counter <= 6) {
aparams.obstacles[obt_counter].radius = rad;
aparams.obstacles[obt_counter].pos = {x, y};
aparams.obstacles[obt_counter].color = csci3081::Color(r, g, b, 255);
obt_counter++;
}
/* thhis if statment ot draw the "home Base"
 * and passing the infomatin ot the aren parameter
 */
} else if (cmd == "HomeBase") {
    csci3081::home_base_params hparams;
    counter++;
    float x, y, rad;
    int r, g, b, ang_del, cd;
    sscanf(line.c_str(), "%s ", command);
    sscanf(line.c_str(),
    "HomeBase %f %f %f %d %d %d %d %d",
    &x, &y, &rad, &r, &g, &b, &ang_del, &cd);
    hparams.angle_delta = ang_del;
    hparams.collision_delta = cd;
    hparams.radius = rad;
    hparams.pos = Position(x, y);
    hparams.color = csci3081::Color(r, g, b, 255);
    std::cout << x << y << rad << r << g << b << std::endl;
    aparams.home_base = hparams;
/* thhis if statment ot draw the "robot" and
 * passing the infomatin ot the aren parameter */
}  else if (cmd == "Robot") {
    counter++;
    float x, y, rad;
    int r, g, b, ang, cd;
    sscanf(line.c_str(), "%s ", command);
    sscanf(line.c_str(),
    "Robot %f %f %f %d %d %d %d %d", &x, &y, &rad, &r, &g, &b, &ang, &cd);
    std::cout << x << y << rad << r << g << b << std::endl;
    if (rbt_counter <= 6) {
    rparams[rbt_counter].radius = rad;
    rparams[rbt_counter].pos = {x, y};
    rparams[rbt_counter].color = csci3081::Color(r, g, b, 255);
    rparams[rbt_counter].angle_delta = ang;
    rparams[rbt_counter].collision_delta = cd;
    aparams.robot[rbt_counter] = rparams[rbt_counter];
    rbt_counter++;
    }
/* thhis if statment ot draw the "SuperBot"
 *  and passing the infomatin ot the aren parameter */
  }  else if (cmd == "SuperBot") {
    csci3081::super_bot_params sparams;
    counter++;
    float x, y, rad;
    int r, g, b, ang, cd;
    sscanf(line.c_str(), "%s ", command);
    sscanf(line.c_str(),
    "SuperBot %f %f %f %d %d %d %d %d", &x, &y, &rad, &r, &g, &b, &ang, &cd);
    std::cout << x << y << rad << r << g << b << std::endl;
    sparams.radius = rad;
    sparams.pos = Position(x, y);
    sparams.color = csci3081::Color(r, g, b, 255);
    sparams.angle_delta = ang;
    sparams.collision_delta = cd;
 /* thhis if statment ot draw the ""RechargeStation""
  * and passing the infomatin ot the aren parameter */
}  else if (cmd == "RechargeStation") {
    counter++;
    float x, y, rad;
    int r, g, b;
    sscanf(line.c_str(), "%s ", command);
    sscanf(
      line.c_str(),
      "RechargeStation %f %f %f %d %d %d", &x, &y, &rad, &r, &g, &b);
    std::cout << x << y << rad << r << g << b << std::endl;
    aparams.recharge_station.radius = rad;
    aparams.recharge_station.pos = {x, y};
    aparams.recharge_station.color = csci3081::Color(r, g, b, 255);
 /* thhis if statment ot draw the "Player"
  * and passing the infomatin ot the arena parameter */
}  else if (cmd == "Player") {
    csci3081::player_params pparams;
    counter++;
    float x, y, rad, bt;
    int r, g, b, ang, cd;
    sscanf(line.c_str(), "%s ", command);
    sscanf(
      line.c_str(),
      "Player %f %f %f %d %d %d %f %d %d",
      &x, &y, &rad, &r, &g, &b, &bt, &ang, &cd);
    std::cout << x << y << rad << r << g << b << std::endl;
    pparams.radius = rad;
    pparams.pos = Position(x, y);
    pparams.color = csci3081::Color(r, g, b, 255);
    pparams.battery_max_charge = bt;
    pparams.angle_delta = ang;
    pparams.collision_delta = cd;
    aparams.player = pparams;
}
}
    csci3081::GraphicsArenaViewer *app =
     new csci3081::GraphicsArenaViewer(&aparams);
    app->Run();
    csci3081::ShutdownGraphics();
    return 0;
}
