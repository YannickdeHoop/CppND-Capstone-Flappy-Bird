//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <game.h>
#include <iostream>
#include <time.h>
#include <random>

// pixels per seconde
constexpr double JUMP_SPEED = 600;
constexpr double FALL_SPEED = 400;
constexpr double MOVE_OBSTACLE_PIXELS_PER_TICK = 5;
constexpr int MIN_HORIZONTAL_PIXELS = 200;
constexpr int MAX_HORIZONTAL_PIXELS = 400;
constexpr int MIN_VERTICAL_PIXELS = 200;
constexpr int MAX_VERTICAL_PIXELS = 500;
constexpr int OBSTACLE_WIDTH = 200;
constexpr double BIRD_INITIAL_X = 100.0;
constexpr double BIRD_INITIAL_Y = 0.0;
namespace flappy_bird
{
Game::Game(const Uint32 target_frame_duration, const std::size_t screen_width, const std::size_t screen_height)
  : scene_state_(SceneState(Bird(pose2d::create(BIRD_INITIAL_X, BIRD_INITIAL_Y, 0))))
  , target_frame_duration_(target_frame_duration)
  , screen_width_(screen_width)
  , screen_heigth_(screen_height)
{
}

void Game::run(Controller& controller, Renderer& renderer)
{
  // State machine which runs the game
  Uint32 frame_start;
  Control control;

  while (true)
  {
    frame_start = SDL_GetTicks();

    control = controller.handleInput();

    if (scene_state_.getCollision() && control.continue_game)
    {
      reset();
    }

    if (!scene_state_.getCollision())
    {
      updateBird(control);
      createNewObstacles();
      deleteObstacles();
      scene_state_.updateObstacles(pose2d::create(-MOVE_OBSTACLE_PIXELS_PER_TICK, 0, 0));
      scene_state_.setCollision(checkCollision());
    }
    renderer.render(scene_state_);

    if (control.quit)
    {
      renderer.~Renderer();
      return;
    }

    waitUntilNextTick(frame_start);
  }
}

void Game::updateBird(const Control& control)
{
  if (control.pressed)
  {
    scene_state_.updateBird(pose2d::create(0, -JUMP_SPEED * (target_frame_duration_ / 1000.0), 0), -JUMP_SPEED);
  }
  else
  {
    scene_state_.updateBird(pose2d::create(0, FALL_SPEED * (target_frame_duration_ / 1000.0), 0), FALL_SPEED);
  }
}

void Game::createNewObstacles()
{
  int horizontal_pixels = getRandomNumber(MIN_HORIZONTAL_PIXELS, MAX_HORIZONTAL_PIXELS);

  if (scene_state_.getObstacles().empty() ||
      scene_state_.getObstacles().back().getPose().translation().x() + scene_state_.getObstacles().back().getWidth() <=
          screen_width_ - horizontal_pixels)
  {
      int vertical_pixels = getRandomNumber(MIN_VERTICAL_PIXELS, MAX_VERTICAL_PIXELS);
    int obstacle_heigth = getRandomNumber(0, screen_heigth_ - vertical_pixels);
    Obstacle upper_obstacle =
        Obstacle(OBSTACLE_WIDTH, obstacle_heigth, pose2d::create(static_cast<double>(screen_width_), 0, 0));
    Obstacle lower_obstacle =
        Obstacle(OBSTACLE_WIDTH, static_cast<int>(screen_heigth_) - vertical_pixels - obstacle_heigth,
                 pose2d::create(static_cast<double>(screen_width_), obstacle_heigth + vertical_pixels, 0));
    scene_state_.addObstacle(upper_obstacle);
    scene_state_.addObstacle(lower_obstacle);
  }
}

void Game::deleteObstacles()
{
  std::vector<Obstacle>& obstacles = scene_state_.getObstacles();
  obstacles.erase(
      std::remove_if(obstacles.begin(), obstacles.end(),
                     [](auto& obstacle) { return obstacle.getWidth() + obstacle.getPose().translation().x() < 0; }),
      obstacles.end());
}

bool Game::checkCollision()
{
  Pose bird_pose = scene_state_.getBird().getPose();
  int bird_width = scene_state_.getBird().getWidth();
  int bird_heigth = scene_state_.getBird().getHeigth();

  std::vector<Obstacle>& obstacles = scene_state_.getObstacles();
  for (auto& obstacle : obstacles)
  {
    auto obstacle_pose = obstacle.getPose();

    if ((bird_pose.translation().x() < obstacle_pose.translation().x() + obstacle.getWidth() &&
         bird_pose.translation().x() + bird_width > obstacle_pose.translation().x() &&
         bird_pose.translation().y() < obstacle_pose.translation().y() + obstacle.getHeigth() &&
         bird_pose.translation().y() + bird_heigth > obstacle_pose.translation().y()) ||
        (bird_pose.translation().y() >= screen_heigth_ || bird_pose.translation().y() <= 0))
    {
      return true;
    }
  }
  return false;
}

void Game::waitUntilNextTick(const Uint32 frame_start)
{
  Uint32 frame_end;
  Uint32 frame_duration;

  frame_end = SDL_GetTicks();

  frame_duration = frame_end - frame_start;

  if (frame_duration < target_frame_duration_)
  {
    SDL_Delay(target_frame_duration_ - frame_duration);
  }
}

void Game::reset()
{
  scene_state_ = SceneState(Bird(pose2d::create(BIRD_INITIAL_X, BIRD_INITIAL_Y, 0)));
}

int Game::getRandomNumber(int min, int max)
{
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_real_distribution<double> distr(min, max);
  return distr(eng);
}
}  // namespace flappy_bird
