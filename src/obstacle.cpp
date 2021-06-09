//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <obstacle.h>
#include <iostream>

namespace flappy_bird
{
Obstacle::Obstacle(const float width, const float heigth, Pose pose) : width_(width), heigth_(heigth), pose_(pose)
{
}

void Obstacle::updatePose(const flappy_bird::Pose& delta_pose)
{
  pose_ = pose_ * delta_pose;
}

Pose Obstacle::getPose()
{
  return pose_;
}

float Obstacle::getWidth()
{
  return width_;
}

float Obstacle::getHeigth()
{
  return heigth_;
}

}  // namespace flappy_bird
