//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <scene_state.h>
#include <iostream>

namespace flappy_bird
{
SceneState::SceneState(Bird bird, double min_velocity, double max_velocity)
  : bird_(bird), min_velocity_(min_velocity), max_velocity_(max_velocity)
{
}

void SceneState::addObstacle(Obstacle obstacle)
{
  obstacles_.push_back(obstacle);
}

void SceneState::updateBird(const double acceleration, const double dt)
{
  double velocity = bird_.getVelocity() + -acceleration * pow(dt, 2);
  limit_velocity(velocity);
  double y = bird_.getPose().translation().y() + velocity * dt;
  bird_.setPose(pose2d::create(bird_.getPose().translation().x(), y, 0));

  bird_.setVelocity(velocity);
}

void SceneState::updateObstacles(const Pose& delta_pose)
{
  for (auto& obstacle : obstacles_)
  {
    obstacle.updatePose(delta_pose);
  }
}

void SceneState::limit_velocity(double& velocity)
{
  if (-velocity > max_velocity_)
  {
    velocity = -max_velocity_;
  }
  else if (-velocity < min_velocity_)
  {
    velocity = -min_velocity_;
  }
}

void SceneState::setCollision(bool collision)
{
  collision_ = collision;
}

bool SceneState::getCollision()
{
  return collision_;
}

std::vector<Obstacle>& SceneState::getObstacles()
{
  return obstacles_;
}

Bird& SceneState::getBird()
{
  return bird_;
}

}  // namespace flappy_bird
