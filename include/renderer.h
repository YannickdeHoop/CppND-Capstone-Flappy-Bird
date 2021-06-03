//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <scene_state.h>

namespace flappy_bird {

class renderer
{
public:
 renderer(const size_t screen_width, const size_t screen_height, const size_t grid_width, const size_t grid_height, const std::string& image_path);
  ~renderer();
  void render(sceneState scene_state);


private:
  SDL_Window* sdl_window_;
  SDL_Renderer* sdl_renderer_;
  SDL_Texture* texture_;
  SDL_Surface* surface_;

  const size_t screen_width_;
  const size_t screen_height_;
  const size_t grid_width_;
  const size_t grid_height_;
};
}
