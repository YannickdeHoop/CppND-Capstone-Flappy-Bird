//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"

namespace flappy_bird
{
class obstacle
{
public:
obstacle(const float width, const float heigth, Pose pose);
void updatePose(const Pose& delta_pose);
Pose getPose();

private:
  Pose pose_;

};
}
