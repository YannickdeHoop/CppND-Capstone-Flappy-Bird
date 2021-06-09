//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include <bird.h>
#include <controller.h>
#include <renderer.h>
#include <obstacle.h>
#include <scene_state.h>
#include "types.h"

namespace flappy_bird
{
class Game
{
public:
  Game(const Uint32 target_frame_duration, std::size_t screen_width, std::size_t screen_height);
  void run(Controller& controller, Renderer& renderer);

private:
  static int getRandomNumber(int min, int max);
  void updateBird(const Control& control);
  void createNewObstacles();
  void deleteObstacles();
  bool checkCollision();
  void waitUntilNextTick(const Uint32 frame_start);
  void reset();
  SceneState scene_state_;
  Uint32 target_frame_duration_;
  std::size_t screen_width_;
  std::size_t screen_heigth_;
};
}  // namespace flappy_bird
