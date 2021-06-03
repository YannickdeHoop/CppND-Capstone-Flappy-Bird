//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#pragma once

#include <bird.h>
#include <controller.h>
#include <renderer.h>
#include <obstacle.h>
#include <scene_state.h>
#include "types.h"

namespace flappy_bird {

class game
{
public:
  game();
  void run(const controller& controller, const renderer& renderer);

private:
  sceneState scene_state_;

};
}
