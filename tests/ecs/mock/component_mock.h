#ifndef COMPONENT_MOCK_H
#define COMPONENT_MOCK_H

#include <gmock/gmock.h>

#include "component.h"

using namespace ecs;

class ComponentMock1 : public Component {
  MOCK_METHOD(std::ostream&, doPrint, (std::ostream & out), (const, override));
};

class ComponentMock2 : public Component {
  MOCK_METHOD(std::ostream&, doPrint, (std::ostream & out), (const, override));
};

class ComponentMock3 : public Component {
  MOCK_METHOD(std::ostream&, doPrint, (std::ostream & out), (const, override));
};

#endif  // COMPONENT_MOCK_H
