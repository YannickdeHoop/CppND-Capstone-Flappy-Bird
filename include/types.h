//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Geometry>

namespace flappy_bird {
//!
//! \brief Orientation and position in 3D space
//!
using Pose = Eigen::Affine3d;

template <typename T>
std::vector<T> operator*(const Pose& pose, const std::vector<T>& v)
{
  std::vector<T> transformed_v;
  for (const auto& e : v)
  {
    transformed_v.emplace_back(pose * e);
  }
  return transformed_v;
}

//!
//! \brief Describes a point in 3D space
//!
using Vector = Eigen::Vector3d;

// Helper functions to work with 2D poses
namespace pose2d
{
//!
//! \brief create Create a Pose from a 3D translation and a 2D angle (roll=0, pitch=0)
//!
Pose create(Vector origin, double yaw);

//!
//! \brief create Create a Pose from 2D information (z=0, roll=0, pitch=0)
//!
Pose create(double x, double y, double yaw);

//!
//! \brief getYaw Get the yaw orientation from a pose
//!
double getYaw(const Pose& pose);

//!
//! \brief getVector Get the x,y,yaw from a pose
//!
Vector getVector(const Pose& pose);
}  // namespace pose2d

struct Control
{
  bool pressed = false;
  bool quit = false;
};
}
