//
// Copyright (c) 2020 Eurotec
//
// @author Yannick de Hoop
//

#include <scene_state.h>


namespace flappy_bird {


bird sceneState::getBird()
{
  return bird_;
}

std::vector<obstacle> sceneState::getObstacles()
{
  return obstacles_;
}

}
