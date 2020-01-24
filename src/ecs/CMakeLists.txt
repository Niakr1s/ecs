cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(ecs SHARED
  entity.cpp
  entity.h
  component.cpp
  component.h
  system.cpp
  system.h
  world.h
  world.cpp
  ecs_time.h

  util/pos.cpp
  util/pos.h

  systems/movesystem.cpp
  systems/movesystem.h

  components/poscomponent.cpp
  components/poscomponent.h
  components/movecomponent.cpp
  components/movecomponent.h
  components/directionmovecomponent.cpp
  components/directionmovecomponent.h
)

target_include_directories(ecs
    PUBLIC
    .
    entities
    systems
    components
    util
)

target_compile_definitions(ecs PRIVATE ECS_LIBRARY)
