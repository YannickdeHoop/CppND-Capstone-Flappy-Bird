//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <iostream>
#include <game.h>
#include <controller.h>
#include <renderer.h>
#include <types.h>

constexpr std::size_t FRAMES_PER_SECOND{ 60 };
constexpr std::size_t FRAME_DURATION{ 1000 / FRAMES_PER_SECOND };
constexpr std::size_t SCREEN_WIDTH{ 1250 };
constexpr std::size_t SCREEN_HEIGHT{ 800 };
constexpr std::size_t GRID_WIDTH{ 25 };
constexpr std::size_t GRID_HEIGHT{ 16 };

int main()
{
  try
  {
    flappy_bird::Renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT);
    flappy_bird::Controller controller;
    flappy_bird::Game game(FRAME_DURATION, SCREEN_WIDTH, SCREEN_HEIGHT);
    game.run(controller, renderer);
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << std::endl;
    return -1;
  }

  return 1;
}
