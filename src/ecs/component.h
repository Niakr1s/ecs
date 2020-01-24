#ifndef COMPONENT_H
#define COMPONENT_H

#include <algorithm>
#include <iostream>
#include <memory>
#include <set>

#include "printable.h"

namespace ecs {

class Component;

using ComponentPtr = std::shared_ptr<Component>;
using ComponentPtrs = std::set<ComponentPtr>;

class Component : public Printable {
 public:
  virtual ~Component() {}
};

}  // namespace ecs

#endif  // COMPONENT_H
