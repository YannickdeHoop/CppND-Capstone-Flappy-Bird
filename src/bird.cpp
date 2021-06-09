//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <bird.h>

namespace flappy_bird
{
Bird::Bird(Pose initial_pose, double initial_velocity, int width, int heigth)
  : pose_(initial_pose), velocity_(velocity_), width_(width), heigth_(heigth)
{
}

Bird::Bird(Pose initial_pose) : pose_(initial_pose)
{
}

void Bird::setPose(Pose pose)
{
  pose_ = pose;
}

void Bird::setVelocity(double velocity)
{
  velocity_ = velocity;
}

Pose Bird::getPose()
{
  return pose_;
}

double Bird::getVelocity()
{
  return velocity_;
}

int Bird::getWidth()
{
  return width_;
}

int Bird::getHeigth()
{
  return heigth_;
}

}  // namespace flappy_bird
