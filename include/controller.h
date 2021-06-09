//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include "types.h"

namespace flappy_bird
{
class Controller
{
public:
  Controller();
  Control handleInput();

private:
  bool last_state_ = false;
};
}  // namespace flappy_bird
