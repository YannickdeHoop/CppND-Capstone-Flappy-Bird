//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <iostream>
#include <renderer.h>

namespace flappy_bird
{
Renderer::Renderer(const size_t screen_width, const size_t screen_height)
  : screen_width_(screen_width), screen_height_(screen_height)
{
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::runtime_error("SDL could not initialize. SDL_Error: " + std::string(SDL_GetError()));
  }

  // Create Window
  sdl_window_ = SDL_CreateWindow("Flappy Bird Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screen_width,
                                 screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window_)
  {
    throw std::runtime_error("Window could not be created. SDL_Error: " + std::string(SDL_GetError()));
  }

  // Create renderer
  sdl_renderer_ = SDL_CreateRenderer(sdl_window_, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer_)
  {
    throw std::runtime_error("Renderer could not be created. SDL_Error: " + std::string(SDL_GetError()));
  }

  // Initialize image loader
  if (IMG_Init(IMG_INIT_PNG) < 0)
  {
    throw std::runtime_error("Image loader could not initialize. SDL_Error: " + std::string(SDL_GetError()));
  }

  // Initialize font loader
  if (TTF_Init() < 0)
  {
    throw std::runtime_error("Text loader could not initialize. SDL_Error: " + std::string(SDL_GetError()));
  }

  font_ = TTF_OpenFont("assets/sans.ttf", 24);
  if (font_ == NULL)
  {
    throw std::runtime_error("Could not load font assest. SDL_Error: " + std::string(SDL_GetError()));
  }

  bird_surface_ = IMG_Load("assets/bird.png");
  if (bird_surface_ == NULL)
  {
    throw std::runtime_error("Could not load PNG assest. SDL_Error: " + std::string(SDL_GetError()));
  }
  bird_texture_ = SDL_CreateTextureFromSurface(sdl_renderer_, bird_surface_);
  SDL_FreeSurface(bird_surface_);
}

Renderer::~Renderer()
{
  SDL_DestroyWindow(sdl_window_);
  SDL_Quit();
}

void Renderer::render(SceneState& scene_state)
{
  auto obstacle_states = scene_state.getObstacles();
  SDL_SetRenderDrawColor(sdl_renderer_, 255, 0, 0, 255);
  SDL_RenderClear(sdl_renderer_);

  for (auto& obstacle_state : obstacle_states)
  {
    renderObstacle(obstacle_state);
  }

  renderBird(scene_state.getBird());
  if (scene_state.getCollision())
  {
    renderText();
  }
  SDL_RenderPresent(sdl_renderer_);

  // TODO: render obstacle states.
}

void Renderer::renderBird(Bird bird_state)
{
  SDL_Rect bird;
  bird.w = 50;
  bird.h = 50;
  bird.x = bird_state.getPose().translation().x();
  bird.y = bird_state.getPose().translation().y();

  double bird_velocity = bird_state.getVelocity();
  double angle = 0;

  angle = bird_velocity < 0 ? angle = -45 : angle = 45;
  SDL_RenderCopyEx(sdl_renderer_, bird_texture_, NULL, &bird, angle, NULL, SDL_FLIP_NONE);
}

void Renderer::renderObstacle(Obstacle obstacle_state)
{
  SDL_SetRenderDrawColor(sdl_renderer_, 38, 166, 91, 255);
  SDL_Rect obstacle;
  obstacle.w = obstacle_state.getWidth();
  obstacle.h = obstacle_state.getHeigth();
  obstacle.x = obstacle_state.getPose().translation().x();
  obstacle.y = obstacle_state.getPose().translation().y();
  SDL_RenderFillRect(sdl_renderer_, &obstacle);
}

void Renderer::renderText()
{
  SDL_Color white = { 255, 255, 255 };
  SDL_Surface* surface_message = TTF_RenderText_Solid(font_, "GAME OVER", white);
  SDL_Texture* message = SDL_CreateTextureFromSurface(sdl_renderer_, surface_message);

  SDL_Rect message_rect_game_over;
  message_rect_game_over.w = 800;
  message_rect_game_over.h = 300;
  message_rect_game_over.x = (screen_width_ / 2) - (message_rect_game_over.w / 2);
  message_rect_game_over.y = (screen_height_ / 2) - (message_rect_game_over.h / 2);
  SDL_RenderCopy(sdl_renderer_, message, NULL, &message_rect_game_over);
  SDL_FreeSurface(surface_message);
  SDL_DestroyTexture(message);

  SDL_Color black = { 0, 0, 0 };
  surface_message = TTF_RenderText_Solid(font_, "PRESS ENTER TO CONTINUE", black);
  message = SDL_CreateTextureFromSurface(sdl_renderer_, surface_message);

  SDL_Rect message_rect_continue;
  message_rect_continue.w = 600;
  message_rect_continue.h = 100;
  message_rect_continue.x = (screen_width_ / 2) - (message_rect_continue.w / 2);
  message_rect_continue.y = message_rect_game_over.y + message_rect_game_over.h + 25;
  SDL_RenderCopy(sdl_renderer_, message, NULL, &message_rect_continue);
  SDL_FreeSurface(surface_message);
  SDL_DestroyTexture(message);
}

}  // namespace flappy_bird
