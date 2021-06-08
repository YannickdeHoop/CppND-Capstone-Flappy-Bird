//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <obstacle.h>

namespace flappy_bird
{
obstacle::obstacle(const float width, const float heigth, Pose pose) : width_(width), heigth_(heigth), pose_(pose)
{
}

void obstacle::updatePose(const flappy_bird::Pose& delta_pose)
{
  pose_ = pose_ * delta_pose;
}

Pose obstacle::getPose()
{
  return pose_;
}

float obstacle::getWidth()
{
  return width_;
}

float obstacle::getHeigth()
{
  return heigth_;
}

}  // namespace flappy_bird
