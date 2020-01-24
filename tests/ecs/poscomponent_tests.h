#ifndef POSCOMPONENT_TESTS_H
#define POSCOMPONENT_TESTS_H

#include <gtest/gtest.h>

#include "components.h"

using namespace ecs;

TEST(poscomponent, plus) {
  PosComponent pos1(2, 2);
  PosComponent pos2(5, -8);

  Pos etalon(7, -6);

  pos1 += pos2;
  ASSERT_EQ(pos1, etalon);
}

TEST(poscomponent, minus) {
  PosComponent pos1(2, 2);
  PosComponent pos2(5, -8);

  Pos etalon(-3, 10);

  pos1 -= pos2;
  ASSERT_EQ(pos1, etalon);
}

#endif  // POSCOMPONENT_TESTS_H
