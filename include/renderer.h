//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <scene_state.h>
#include <SDL_ttf.h>

namespace flappy_bird
{
class Renderer
{
public:
  Renderer(const size_t screen_width, const size_t screen_height);
  ~Renderer();
  void render(SceneState& scene_state);

private:
  void renderBird(Bird bird_state);
  void renderObstacle(Obstacle obstacle_state);
  void renderText();
  SDL_Window* sdl_window_;
  SDL_Renderer* sdl_renderer_;
  SDL_Texture* bird_texture_;
  SDL_Surface* bird_surface_;
  TTF_Font* font_;

  const size_t screen_width_;
  const size_t screen_height_;
};
}  // namespace flappy_bird
