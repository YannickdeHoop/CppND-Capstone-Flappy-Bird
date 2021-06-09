//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"

namespace flappy_bird
{
class Obstacle
{
public:
  Obstacle(const float width, const float heigth, Pose pose);
  void updatePose(const Pose& delta_pose);
  Pose getPose();
  float getWidth();
  float getHeigth();

private:
  Pose pose_;
  float width_;
  float heigth_;
};
}  // namespace flappy_bird
