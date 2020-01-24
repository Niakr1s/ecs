#ifndef MOVESYSTEM_TESTS_H
#define MOVESYSTEM_TESTS_H

#include <gtest/gtest.h>

#include <cmath>

#include "components.h"
#include "systems.h"
#include "world.h"

using namespace ecs;

TEST(movesystem, test1) {
  std::shared_ptr<DirectionMoveComponent> dir_move_c(
      new DirectionMoveComponent(Angle(0.), 2. / 1000.));

  Pos old_pos(50, 50);
  std::shared_ptr<PosComponent> pos_c(new PosComponent(old_pos));

  std::shared_ptr<MoveSystem> move_s(new MoveSystem());

  dir_move_c->move(pos_c, std::chrono::seconds(1));

  Pos expect_pos(52, 50);

  ASSERT_NE(*pos_c, old_pos);
  ASSERT_EQ(*pos_c, expect_pos);
}

#endif  // MOVESYSTEM_TESTS_H
