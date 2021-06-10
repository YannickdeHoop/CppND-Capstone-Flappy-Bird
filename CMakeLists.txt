cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(flappy_bird)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(Eigen3 REQUIRED)

configure_file(assets/bird.png assets/bird.png COPYONLY)
configure_file(assets/sans.ttf assets/sans.ttf COPYONLY)

include_directories(
  ${SDL2_INCLUDE_DIRS}
  ${SDL2_IMAGE_INCLUDE_DIRS}
  ${SDL2_TTF_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIRS}
  include)

add_definitions(${EIGEN3_DEFINITIONS})

add_executable(${PROJECT_NAME}
  src/main.cpp
  src/bird.cpp
  src/controller.cpp
  src/game.cpp
  src/scene_state.cpp
  src/obstacle.cpp
  src/renderer.cpp
  src/types.cpp)
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} SDL2_image SDL2_ttf)
