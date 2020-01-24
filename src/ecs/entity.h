#ifndef ENTITY_H
#define ENTITY_H

#include <algorithm>
#include <vector>

#include "component.h"

namespace ecs {

class Entity;

using EntityPtr = std::shared_ptr<Entity>;
using EntityPtrs = std::vector<EntityPtr>;

class Entity {
 public:
  Entity();

  void addComponent(const ComponentPtr& component);
  void removeComponent(const ComponentPtr& component);

  inline size_t componentsSize() { return components_.size(); }

  template <class Component_T>
  ComponentPtr component() {
    auto found =
        std::find_if(std::cbegin(components_), std::cend(components_),
                     [](const ComponentPtr& component) -> bool {
                       return dynamic_cast<Component_T*>(component.get());
                     });
    return found == components_.cend() ? ComponentPtr() : *found;
  }

  template <class... Args>
  ComponentPtrs components() {
    ComponentPtrs res{component<Args>()...};
    res.erase(nullptr);
    return res;
  }

  template <class... Args>
  static EntityPtrs filter(const EntityPtrs& entities) {
    EntityPtrs res;
    std::copy_if(std::begin(entities), std::end(entities),
                 std::back_inserter(res), [](const EntityPtr& entity) {
                   return ((entity->component<Args>()) && ...);
                 });
    return res;
  }

 protected:
  ComponentPtrs components_;
};

}  // namespace ecs

#endif  // ENTITY_H
