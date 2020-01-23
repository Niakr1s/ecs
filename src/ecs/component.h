#ifndef COMPONENT_H
#define COMPONENT_H

#include <algorithm>
#include <memory>
#include <vector>

namespace ecs {

class Component;

using ComponentPtr = std::shared_ptr<Component>;
using ComponentPtrs = std::vector<ComponentPtr>;

class Component {
 public:
  Component();
  virtual ~Component() {}

  template <class... Args>
  static ComponentPtrs filter(const ComponentPtrs& components) {
    ComponentPtrs res;
    std::copy_if(std::begin(components), std::end(components),
                 std::back_inserter(res), [](const ComponentPtr& component) {
                   return (dynamic_cast<Args*>(component.get()) || ...);
                 });
    return res;
  }
};

}  // namespace ecs

#endif  // COMPONENT_H
