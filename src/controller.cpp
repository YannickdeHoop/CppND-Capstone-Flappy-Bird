//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <controller.h>
#include <SDL.h>

namespace flappy_bird
{
Controller::Controller()
{
}

Control Controller::handleInput()
{
  Control control;
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    if (e.key.keysym.sym == SDLK_ESCAPE || e.type == SDL_QUIT)
    {
      control.quit = true;
    }
    else if (e.type == SDL_KEYDOWN && e.key.keysym.scancode == SDL_SCANCODE_RETURN)
    {
      control.continue_game = true;
      last_state_ = false;
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
