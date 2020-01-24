#ifndef SYSTEM_TESTS_H
#define SYSTEM_TESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <thread>

#include "mock/entity_mock.h"
#include "mock/system_mock.h"
#include "world.h"

using ::testing::_;
using ::testing::AtLeast;

using namespace ecs;

TEST(system, works) {
  auto system = std::make_shared<SystemMock1>();
  EXPECT_CALL(*system, process).Times(AtLeast(1));

  World w;
  w.addSystem(system);

  auto t = std::thread([&] { w.start(); });
  t.detach();

  std::this_thread::sleep_for(std::chrono::microseconds(10));
  w.stop();
  std::this_thread::sleep_for(std::chrono::microseconds(100));
}

#endif  // SYSTEM_TESTS_H
