#ifndef SYSTEM_MOCK_H
#define SYSTEM_MOCK_H

#include <gmock/gmock.h>

#include "system.h"

using namespace ecs;

class SystemMock1 : public System {
 public:
  MOCK_METHOD(void, process,
              (const ecs::World& world, std::chrono::milliseconds diff),
              (override));
  MOCK_METHOD(std::ostream&, doPrint, (std::ostream & out), (const, override));
};

// class SystemMock2 : public System {};

#endif  // SYSTEM_MOCK_H
