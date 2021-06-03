//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"
#include "obstacle.h"
#include "bird.h"

namespace flappy_bird {

class sceneState
{
public:
  sceneState(bird&& bird);
  void addObstacle(obstacle&& obstacle);
  void updateBird(const Pose& delta_pose, const double delta_velocity);
  void updateObstacles(const Pose& delta_pose);
  std::vector<obstacle> getObstacles();
  bird getBird();

private:
  bird bird_;
  std::vector<obstacle> obstacles_;

};
}
