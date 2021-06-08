//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <controller.h>
#include <SDL.h>
#include <iostream>

namespace flappy_bird
{
controller::controller()
{
}

Control controller::handleInput()
{
  Control control;
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.key.keysym.sym == SDLK_ESCAPE)
    {
      control.quit = true;
    }
    else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
    {
      control.pressed = true;
      last_state_ = control.pressed;
    }
    else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_SPACE)
    {
      control.pressed = false;
      last_state_ = control.pressed;
    }
    else
    {
      control.pressed = last_state_;
    }
    return control;
  }

  control.pressed = last_state_;
  return control;
}
}  // namespace flappy_bird
