//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <iostream>
#include <renderer.h>

namespace flappy_bird {

renderer::renderer(const size_t screen_width, const size_t screen_height, const size_t grid_width, const size_t grid_height, const std::string& image_path)
  : screen_width_(screen_width),
    screen_height_(screen_height),
    grid_width_(grid_width),
    grid_height_(grid_height){

  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ = SDL_CreateWindow("Flappy Bird Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
  SDL_SetRenderDrawColor(sdl_renderer_, 255, 0, 0, 255);
  SDL_RenderClear(sdl_renderer_);

  // Initialize image loader
  if (IMG_Init(IMG_INIT_PNG) < 0)
  {
    std::cerr << "Image loader could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  surface_ = IMG_Load(image_path.c_str());
  texture_ = SDL_CreateTextureFromSurface(sdl_renderer_, surface_);
  SDL_FreeSurface(surface_);
}

renderer::~renderer() {
  SDL_DestroyWindow(sdl_window_);
  SDL_Quit();
}

void renderer::render(sceneState scene_state)
{
  auto bird_state = scene_state.getBird();
  auto obstacle_states = scene_state.getObstacles();

  SDL_Rect bird;
  bird.w = 100;
  bird.h = 100;
  bird.x = bird_state.getPose().translation().x();
  bird.y = bird_state.getPose().translation().y();

  double bird_velocity = bird_state.getVelocity();
  double angle = 0;

  angle = bird_velocity < 0 ? angle = -45 : angle = 45;

  SDL_RenderCopyEx(sdl_renderer_, texture_, NULL, &bird, angle, NULL, SDL_FLIP_NONE);
  SDL_RenderPresent(sdl_renderer_);

}


}
