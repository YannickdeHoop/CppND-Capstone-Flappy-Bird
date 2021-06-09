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
  SceneState(Bird bird);
  void addObstacle(Obstacle obstacle);
  void updateBird(Pose pose, double velocity);
  void updateObstacles(const Pose& delta_pose);
  void setCollision(bool collision);
  bool getCollision();
  std::vector<Obstacle>& getObstacles();
  Bird& getBird();

private:
  Bird bird_;
  std::vector<Obstacle> obstacles_;
  bool collision_ = false;
};
}  // namespace flappy_bird
