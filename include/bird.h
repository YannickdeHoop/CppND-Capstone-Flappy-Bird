//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"

namespace flappy_bird {
class bird
{
public:
  bird(Pose initial_pose, double initial_velocity);
  bird(Pose initial_pose);
  void setPose(Pose pose);
  void setVelocity(double velocity);
  Pose getPose();
  double getVelocity();

private:
  Pose pose_;
  double velocity_ = 0;
};
}
