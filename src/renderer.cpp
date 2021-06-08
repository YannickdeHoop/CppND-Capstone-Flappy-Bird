//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <iostream>
#include <renderer.h>

namespace flappy_bird
{
renderer::renderer(const size_t screen_width, const size_t screen_height, const size_t grid_width,
                   const size_t grid_height, const std::string& image_path)
  : screen_width_(screen_width), screen_height_(screen_height), grid_width_(grid_width), grid_height_(grid_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window_ = SDL_CreateWindow("Flappy Bird Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width,
                                 screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_)
  {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  std::cout << "initialize" << std::endl;
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_)
  {
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

  bird_surface_ = IMG_Load(image_path.c_str());
  bird_texture_ = SDL_CreateTextureFromSurface(sdl_renderer_, bird_surface_);
  SDL_FreeSurface(bird_surface_);
}

renderer::~renderer()
{
  SDL_DestroyWindow(sdl_window_);
  SDL_Quit();
}

void renderer::render(sceneState& scene_state)
{
  auto obstacle_states = scene_state.getObstacles();
  SDL_RenderClear(sdl_renderer_);

  //  for(auto& obstacle_state : obstacle_states)
  //  {
  //    renderObstacle(obstacle_state);
  //  }

  renderBird(scene_state.getBird());

  SDL_RenderPresent(sdl_renderer_);

  // TODO: render obstacle states.
}

void renderer::renderBird(bird bird_state)
{
  SDL_Rect bird;
  bird.w = screen_width_ / grid_width_;
  bird.h = screen_height_ / grid_height_;
  bird.x = bird_state.getPose().translation().x();
  bird.y = bird_state.getPose().translation().y();

  double bird_velocity = bird_state.getVelocity();
  double angle = 0;

  angle = bird_velocity < 0 ? angle = -45 : angle = 45;
  SDL_RenderCopyEx(sdl_renderer_, bird_texture_, NULL, &bird, angle, NULL, SDL_FLIP_NONE);
}

void renderer::renderObstacle(obstacle obstacle_state)
{
  SDL_SetRenderDrawColor(sdl_renderer_, 38, 166, 91, 255);
  SDL_Rect obstacle;
  obstacle.w = obstacle_state.getWidth();
  obstacle.h = obstacle_state.getHeigth();
  obstacle.x = obstacle_state.getPose().translation().x();
  obstacle.y = obstacle_state.getPose().translation().y();
  SDL_RenderDrawRect(sdl_renderer_, &obstacle);
}

}  // namespace flappy_bird
