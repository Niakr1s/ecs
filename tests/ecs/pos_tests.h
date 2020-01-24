#ifndef POS_TESTS_H
#define POS_TESTS_H

#include <gtest/gtest.h>

#include "pos.h"

using namespace ecs;

TEST(pos, plus) {
  Pos pos1(2, 2);
  Pos pos2(5, -8);

  Pos etalon(7, -6);

  ASSERT_EQ(pos1 + pos2, etalon);

  pos1 += pos2;
  ASSERT_EQ(pos1, etalon);
}

TEST(pos, minus) {
  Pos pos1(2, 2);
  Pos pos2(5, -8);

  Pos etalon(-3, 10);

  ASSERT_EQ(pos1 - pos2, etalon);

  pos1 -= pos2;
  ASSERT_EQ(pos1, etalon);
}

TEST(pos, copy_constructor) {
  Pos pos1(2, 2);
  Pos pos2(pos1);

  ASSERT_EQ(pos1, pos2);
}

#endif  // POS_TESTS_H
