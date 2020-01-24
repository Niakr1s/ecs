#ifndef MOVESYSTEM_TESTS_H
#define MOVESYSTEM_TESTS_H

#include <gtest/gtest.h>

#include "systems.h"
#include "world.h"

using namespace ecs;

TEST(movesystem, test1) {
  World w;
  MoveSystem move;
}

#endif  // MOVESYSTEM_TESTS_H
