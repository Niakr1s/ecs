#ifndef ENTITY_H
#define ENTITY_H

#include <algorithm>

#include "component.h"

namespace ecs {

class Entity {
 public:
  Entity();

  void addComponent(const ComponentPtr& component);
  void removeComponent(const ComponentPtr& component);

  inline size_t componentsSize() { return components_.size(); }

  template <class... Args>
  ComponentPtrs filterComponents() {
    return Component::filter<Args...>(components_);
  }

 protected:
  ComponentPtrs components_;
};

}  // namespace ecs

#endif  // ENTITY_H
