//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <types.h>

namespace  flappy_bird {
//! note: We use tf2::Matrix3x3::getRPY here since is will find a solution in yaw first
void getRPY(const Pose& pose, double& roll, double& pitch, double& yaw)
{
  Eigen::Quaterniond q(pose.linear());
  Eigen::Vector3d eulerAngle = q.matrix().eulerAngles(0,1,2);
  roll = eulerAngle[0];
  pitch = eulerAngle[1];
  yaw = eulerAngle[2];
}

namespace pose2d
{
Pose create(Vector origin, double yaw)
{
  return Pose(Eigen::Translation3d(origin) * Eigen::Quaterniond(Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitZ())));
}

Pose create(double x, double y, double yaw)
{
  return Pose(Eigen::Translation3d(x, y, 0) * Eigen::Quaterniond(Eigen::AngleAxisd(yaw, Eigen::Vector3d::UnitZ())));
}

double getYaw(const Pose& pose)
{
  double roll, pitch, yaw;
  getRPY(pose, roll, pitch, yaw);
  return yaw;
}

Vector getVector(const Pose& pose)
{
  return Vector(pose.translation().x(), pose.translation().y(), getYaw(pose));
}
}  // namespace pose2d
}
