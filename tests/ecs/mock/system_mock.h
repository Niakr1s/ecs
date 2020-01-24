#ifndef SYSTEM_MOCK_H
#define SYSTEM_MOCK_H

#include <gmock/gmock.h>

#include "system.h"

using namespace ecs;

class SystemMock1 : public System {
 public:
  MOCK_METHOD(void, process, (const ecs::World& world, Time_diff_ns_t diff_ns),
              (override));
};

// class SystemMock2 : public System {};

#endif  // SYSTEM_MOCK_H
