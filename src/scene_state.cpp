//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <scene_state.h>
#include <iostream>

namespace flappy_bird
{
SceneState::SceneState(Bird bird)
  : bird_(bird)
{
}

void SceneState::addObstacle(Obstacle obstacle)
{
  obstacles_.push_back(obstacle);
}

void SceneState::updateBird(Pose delta_pose, double velocity)
{
  bird_.setPose(bird_.getPose() * delta_pose);
  bird_.setVelocity(velocity);
}

void SceneState::updateObstacles(const Pose& delta_pose)
{
  for (auto& obstacle : obstacles_)
  {
    obstacle.updatePose(delta_pose);
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
