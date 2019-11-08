/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include <iostream>
#include <string>
#include <vector>

#include "src/player.h"
#include "src/robot.h"
#include "src/home_base.h"
#include "src/obstacle.h"
#include "src/arena_params.h"
#include "src/event_keypress.h"

/*******************************************************************************
 * Namespaces

/*! Namespaces Begin */
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(
  const struct arena_params* const params)
    : csci3081::GraphicsApp(params->x_dim, params->y_dim, "Robot Simulation"),
      arena_(new Arena(params)),
      paused_(false),
      pause_btn_(nullptr) {
  nanogui::FormHelper *gui = new nanogui::FormHelper(this);
  nanogui::ref<nanogui::Window> window = gui->addWindow(Eigen::Vector2i(10, 10),
                                                       "Simulation Controls");
  gui->addButton("Restart",
    std::bind(&GraphicsArenaViewer::OnRestartBtnPressed, this));
  pause_btn_ = gui->addButton("Pause",
    std::bind(&GraphicsArenaViewer::OnPauseBtnPressed, this));

  performLayout();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
  if (!paused_) {
    last_dt += dt;
    while (last_dt > 0.05) {
      arena_->AdvanceTime();
      last_dt -= 0.05;
    }
  }
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnRestartBtnPressed() {
  arena_->Reset();
}

void GraphicsArenaViewer::OnPauseBtnPressed() {
  paused_ = !paused_;
  if (paused_) {
    pause_btn_->setCaption("Play");
  } else {
    pause_btn_->setCaption("Pause");
  }
}

void GraphicsArenaViewer::OnMouseMove(int x, int y) {
  std::cout << "Mouse moved to (" << x << ", " << y << ")" << std::endl;
}

void GraphicsArenaViewer::OnLeftMouseDown(int x, int y) {
  std::cout << "Left mouse button DOWN (" << x << ", " << y << ")" << std::endl;
}

void GraphicsArenaViewer::OnLeftMouseUp(int x, int y) {
  std::cout << "Left mouse button UP (" << x << ", " << y << ")" << std::endl;
}

void GraphicsArenaViewer::OnRightMouseDown(int x, int y) {
  std::cout << "Right mouse button DOWN (" << x << ", " << y << ")\n";
}

void GraphicsArenaViewer::OnRightMouseUp(int x, int y) {
  std::cout << "Right mouse button UP (" << x << ", " << y << ")" << std::endl;
}

void GraphicsArenaViewer::OnKeyDown(const char *c, int modifiers) {
  std::cout << "Key DOWN (" << c << ") modifiers=" << modifiers << std::endl;
}

void GraphicsArenaViewer::OnKeyUp(const char *c, int modifiers) {
  std::cout << "Key UP (" << c << ") modifiers=" << modifiers << std::endl;
}

void GraphicsArenaViewer::OnSpecialKeyDown(int key, int scancode,
  int modifiers) {
  EventKeypress e(key);
  arena_->Accept(&e);
  std::cout << "Special Key DOWN key=" << key << " scancode=" << scancode
            << " modifiers=" << modifiers << std::endl;
}

void GraphicsArenaViewer::OnSpecialKeyUp(int key, int scancode, int modifiers) {
  std::cout << "Special Key UP key=" << key << " scancode=" << scancode
            << " modifiers=" << modifiers << std::endl;
}

/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/
  // translate and rotate all graphics calls that follow so that they are
  // centered, at the position and heading for this player
  void GraphicsArenaViewer::DrawPlayer(
    NVGcontext *ctx, const Player* const player) {
  nvgSave(ctx);
  nvgTranslate(ctx, player->get_pos().x, player->get_pos().y);
  nvgRotate(ctx, player->heading_angle());

  // player's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, player->radius());
  nvgFillColor(ctx, nvgRGBA(player->color().r,
                            player->color().g,
                            player->color().b,
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // player id text label
  nvgSave(ctx);
  nvgRotate(ctx, M_PI / 2.0);
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  /*
   * This call to print the level of the battey on the window of the game
   * under the player name
   */
  nvgText(ctx, 0.0, 30.0, player->str_battery_level().c_str(), NULL);
  /*
   * This call to print the status of the user when the game is end. If he/she
   * lost the game will print "YOU LOST THE GAME, Restart Again"
   * while in the winning situation will print "WOW, YOU WON THE GAME"
   */
  nvgText(ctx, 0.0, 50.0, player->endGame().c_str(), NULL);
  nvgText(ctx, 0.0, 10.0, player->name().c_str(), NULL);
  nvgRestore(ctx);
  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawRobot(NVGcontext *ctx, const Robot* const robot) {
nvgSave(ctx);
nvgTranslate(ctx, robot->get_pos().x, robot->get_pos().y);
nvgRotate(ctx, robot->heading_angle());

// player's circle
nvgBeginPath(ctx);
nvgCircle(ctx, 0.0, 0.0, robot->radius());
nvgFillColor(ctx, nvgRGBA(robot->color().r,
                          robot->color().g,
                          robot->color().b,
                          255));
nvgFill(ctx);
nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
nvgStroke(ctx);

// player id text label
nvgSave(ctx);
nvgRotate(ctx, M_PI / 2.0);
nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));

nvgText(ctx, 0.0, 10.0, robot->name().c_str(), NULL);
nvgRestore(ctx);
nvgRestore(ctx);
}

/*
* this function is to draw the sensor arounf the  robots
*/
/*
*@bug the sensor is not drawen as a cone it is drawen an a full circle
*/
void GraphicsArenaViewer::DrawSensor(
  NVGcontext *ctx, const Robot* const robot) {
  // translate and rotate all graphics calls that follow so that they are
  // centered at the position and heading for this robot

  nvgSave(ctx);
  nvgTranslate(ctx, robot->get_pos().x, robot->get_pos().y);
  double angle = std::atan2(robot->get_pos().y,  robot->get_pos().x);
  nvgRotate(ctx, angle);

  // sensor cone outline
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * 20);
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, 50, 0.0);  //  sensor_dist = 10
  //  sensor_dist = 10 sensor_angle = 20
  nvgArc(ctx, 0.0, 0.0, 50, 0.0, -20, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 100));
  nvgStroke(ctx);
  nvgRestore(ctx);

  // blue for right sensor cone
  nvgSave(ctx);
  nvgRotate(ctx, 0.5 * 20);  //  sensor_angle=20
  nvgBeginPath(ctx);
  nvgMoveTo(ctx, 0.0, 0.0);
  nvgLineTo(ctx, 50, 0.0);   //  sensor_dist = 10
  //  sensor_dist = 10 angle
  nvgArc(ctx, 0.0, 0.0, 50, 0.0, -0.5 * 20, NVG_CCW);
  nvgLineTo(ctx, 0.0, 0.0);
  nvgFillColor(ctx, nvgRGBA(100, 100, 255, 150));
  nvgFill(ctx);
  nvgRestore(ctx);

  // // yellow for left sensor cone
  // nvgSave(ctx);
  // nvgBeginPath(ctx);
  // nvgMoveTo(ctx, 0.0, 0.0);
  // nvgLineTo(ctx, 50, 0.0); //sensor_dist = 10
  // nvgArc(ctx, 0.0, 0.0, 50, 0.0, -0.5 * 20, NVG_CCW); // sensor_dist angle
  // nvgLineTo(ctx, 0.0, 0.0);
  // nvgFillColor(ctx, nvgRGBA(255, 255, 100, 150));
  // nvgFill(ctx);
  // nvgRestore(ctx);

  nvgRestore(ctx);
}


void GraphicsArenaViewer::DrawObstacle(NVGcontext *ctx,
                                       const Obstacle* const obstacle) {
  nvgBeginPath(ctx);
  nvgCircle(ctx, obstacle->get_pos().x, obstacle->get_pos().y,
    obstacle->radius());
  nvgFillColor(ctx, nvgRGBA(obstacle->color().r,
                            obstacle->color().g,
                            obstacle->color().b,
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, obstacle->get_pos().x, obstacle->get_pos().y,
          obstacle->name().c_str(), NULL);
}

void GraphicsArenaViewer::DrawHomeBase(NVGcontext *ctx,
                               const HomeBase* const home) {
 /*
  * The home base is drawen exactly as the player is done except the battery
  * level and the status of the game when it ends
  */
  nvgSave(ctx);
  nvgTranslate(ctx, home->get_pos().x, home->get_pos().y);
  nvgRotate(ctx, home->heading_angle());

  nvgBeginPath(ctx);
  nvgCircle(ctx, 60.0, 60.0, home->radius());
  nvgFillColor(ctx, nvgRGBA(home->color().r,
                            home->color().g,
                            home->color().b,
                            255));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgSave(ctx);
  nvgRotate(ctx, M_PI / 3.0);
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, 80, -20, home->name().c_str(), NULL);
  nvgRestore(ctx);
  nvgRestore(ctx);
}

// This is the primary driver for drawing all entities in the arena.
// It is called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // initialize text rendering settings
  nvgFontSize(ctx, 18.0f);
  nvgFontFace(ctx, "sans-bold");
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

  std::vector<Obstacle*> obstacles = arena_->obstacles();
  for (size_t i = 0; i < obstacles.size(); i++) {
    DrawObstacle(ctx, obstacles[i]);
  } /* for(i..) */
  DrawHomeBase(ctx, arena_->home_base());
  DrawObstacle(ctx, arena_ -> recharge_station());

/*
  * The robots is drawen exactly as the player is done except the battery
  * level and the status of the game when it ends
  * we use for loop because we have a vecotor of robots
  */
  std::vector<Robot*> robots = arena_-> robots();
  for (size_t j = 0; j < robots.size(); j++) {
      DrawSensor(ctx, robots[j]);
      DrawRobot(ctx, robots[j]);
  } /* for(i..) */
  /* the player is drawen */
  DrawPlayer(ctx, arena_->player());
}

/*! Namespaces End */
NAMESPACE_END(csci3081);
