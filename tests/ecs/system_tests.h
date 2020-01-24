#ifndef SYSTEM_TESTS_H
#define SYSTEM_TESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mock/entity_mock.h"
#include "mock/system_mock.h"
#include "world.h"

using ::testing::_;
using ::testing::AtLeast;

using namespace ecs;

TEST(system, works) {
  auto system = std::make_shared<SystemMock1>();
  EXPECT_CALL(*system, process(_)).Times(AtLeast(1));

  World w;
  w.addSystem(system);

  EXPECT_NO_THROW(w.nextFrame());
}

#endif  // SYSTEM_TESTS_H
