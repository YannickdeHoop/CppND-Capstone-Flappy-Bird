//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"
#include "obstacle.h"
#include "bird.h"

namespace flappy_bird
{
class SceneState
{
public:
  SceneState(Bird bird, double min_velocity, double max_velocity);
  void addObstacle(Obstacle obstacle);
  void updateBird(const double acceleration, const double dt);
  void updateObstacles(const Pose& delta_pose);
  void limit_velocity(double& velocity);
  void setCollision(bool collision);
  bool getCollision();
  std::vector<Obstacle>& getObstacles();
  Bird& getBird();

private:
  Bird bird_;
  std::vector<Obstacle> obstacles_;
  double max_velocity_ = 5.0;
  double min_velocity_ = -5.0;
  bool collision_ = false;
};
}  // namespace flappy_bird
