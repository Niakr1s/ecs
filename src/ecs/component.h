#ifndef COMPONENT_H
#define COMPONENT_H

#include <algorithm>
#include <memory>
#include <set>

namespace ecs {

class Component;

using ComponentPtr = std::shared_ptr<Component>;
using ComponentPtrs = std::set<ComponentPtr>;

class Component {
 public:
  virtual ~Component() {}
};

}  // namespace ecs

#endif  // COMPONENT_H
