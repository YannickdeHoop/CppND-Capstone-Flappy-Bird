//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"

namespace flappy_bird
{
class Bird
{
public:
  Bird(Pose initial_pose, double initial_velocity, int width, int heigth);
  Bird(Pose initial_pose);
  void setPose(Pose pose);
  void setVelocity(double velocity);
  Pose getPose();
  double getVelocity();
  int getWidth();
  int getHeigth();

private:
  Pose pose_;
  double velocity_ = 0;
  int width_ = 50;
  int heigth_ = 50;
};
}  // namespace flappy_bird
