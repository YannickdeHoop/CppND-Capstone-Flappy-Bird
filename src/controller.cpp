//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <controller.h>
#include <SDL.h>

namespace flappy_bird {

controller::controller()
{

}

Control controller::handleInput() const
{
  Control control;
  SDL_Event e;

  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
    {
      control.quit = true;
    }
    else if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE)
    {
      control.pressed = true;
    }
  }
  return control;
}

}
