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
  flappy_bird::renderer renderer(SCREEN_WIDTH, SCREEN_HEIGHT, GRID_WIDTH, GRID_HEIGHT, "assets/bird.png");
  flappy_bird::controller controller;
  flappy_bird::game game(FRAME_DURATION, SCREEN_WIDTH, SCREEN_HEIGHT);
  game.run(controller, renderer);
  return 1;
}
