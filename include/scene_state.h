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
class sceneState
{
public:
  sceneState(bird&& bird, double min_velocity, double max_velocity);
  void addObstacle(obstacle&& obstacle);
  void updateBird(const double acceleration, const double dt);
  void updateObstacles(const Pose& delta_pose);
  void limit_velocity(double& velocity);
  std::vector<obstacle>& getObstacles();
  bird& getBird();

private:
  bird bird_;
  std::vector<obstacle> obstacles_;
  double max_velocity_ = 5.0;
  double min_velocity_ = -5.0;
};
}  // namespace flappy_bird
