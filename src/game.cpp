//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <game.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>

constexpr double BIRD_ACCELERATION = 50000;
constexpr size_t PIXELS_PER_TICK = 5;
constexpr int MAX_PIXEL_BETWEEN_OBSTACLES = 300;
constexpr int MIN_PIXEL_BETWEEN_OBSTACLES = 100;

namespace flappy_bird
{
game::game(const Uint32 target_frame_duration, const std::size_t screen_width, const std::size_t screen_height)
  : scene_state_(sceneState(std::move(bird(pose2d::create(100, 0, 0), 0)), -150.0, 200.0))
  , target_frame_duration_(target_frame_duration)
  , screen_width_(screen_width)
  , screen_heigth_(screen_height)
{
}

void game::run(controller& controller, renderer& renderer)
{
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  Control control;

  while (true)
  {
    frame_start = SDL_GetTicks();

    control = controller.handleInput();
    proccessControl(control);
    createNewObstacles();
    deleteObstacles();
    scene_state_.updateObstacles(pose2d::create(PIXELS_PER_TICK, 0, 0));
    renderer.render(scene_state_);

    frame_end = SDL_GetTicks();

    frame_duration = frame_end - frame_start;

    if (frame_duration < target_frame_duration_)
    {
      SDL_Delay(target_frame_duration_ - frame_duration);
    }

    if (control.quit)
    {
      renderer.~renderer();
      return;
    }
  }
}

void game::proccessControl(const Control& control)
{
  if (control.pressed)
  {
    scene_state_.updateBird(BIRD_ACCELERATION, target_frame_duration_ / 1000.0);
  }
  else
  {
    scene_state_.updateBird(-BIRD_ACCELERATION, target_frame_duration_ / 1000.0);
  }
}

void game::createNewObstacles()
{
  srand(time(NULL));
  int pixels_between_obstacle = rand() % MAX_PIXEL_BETWEEN_OBSTACLES + MIN_PIXEL_BETWEEN_OBSTACLES;
}

void game::deleteObstacles()
{
}

}  // namespace flappy_bird
