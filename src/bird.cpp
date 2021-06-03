//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <bird.h>

namespace flappy_bird {

bird::bird(Pose initial_pose, double initial_velocity): pose_(initial_pose), velocity_(velocity_)
{

}

bird::bird(Pose initial_pose): pose_(initial_pose)
{

}

void bird::setPose(Pose pose)
{
  pose_ = pose;
}

void bird::setVelocity(double velocity)
{
  velocity_ = velocity;
}

Pose bird::getPose()
{
 return pose_;
}

double bird::getVelocity()
{
  return velocity_;
}

}
