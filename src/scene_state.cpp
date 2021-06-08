//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <scene_state.h>
#include <iostream>

namespace flappy_bird
{
sceneState::sceneState(bird&& bird, double min_velocity, double max_velocity)
  : bird_(bird), min_velocity_(min_velocity), max_velocity_(max_velocity)
{
}

void sceneState::addObstacle(obstacle&& obstacle)
{
}

void sceneState::updateBird(const double acceleration, const double dt)
{
  double velocity = bird_.getVelocity() + -acceleration * pow(dt, 2);
  limit_velocity(velocity);
  double y = bird_.getPose().translation().y() + velocity * dt;
  std::cout << velocity << std::endl;
  bird_.setPose(pose2d::create(bird_.getPose().translation().x(), y, 0));

  bird_.setVelocity(velocity);
}

void sceneState::updateObstacles(const Pose& delta_pose)
{
  for (auto& obstacle : obstacles_)
  {
    obstacle.updatePose(delta_pose);
  }
}

void sceneState::limit_velocity(double& velocity)
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

std::vector<obstacle>& sceneState::getObstacles()
{
  return obstacles_;
}

bird& sceneState::getBird()
{
  return bird_;
}

}  // namespace flappy_bird
