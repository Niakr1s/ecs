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

  template <class Component_T, class... Args>
  void setComponent(Args... args);

  template <class Component_T>
  bool removeComponent();

  template <class Component_T>
  bool componentExists();

  template <class Component_T>
  ComponentPtr component();

  template <class... Args>
  ComponentPtrs components();

  inline size_t componentsSize() { return components_.size(); }

  template <class... Args>
  static EntityPtrs filter(const EntityPtrs& entities);

 protected:
  ComponentPtrs components_;
};

template <class Component_T>
bool Entity::componentExists() {
  return component<Component_T>();
}

template <class Component_T, class... Args>
void Entity::setComponent(Args... args) {
  components_.insert(ComponentPtr(new Component_T(args...)));
}

template <class Component_T>
bool Entity::removeComponent() {
  ComponentPtr c = component<Component_T>();
  if (!c) return false;

  components_.erase(c);
  return true;
}

template <class Component_T>
ComponentPtr Entity::component() {
  auto found =
      std::find_if(std::cbegin(components_), std::cend(components_),
                   [](const ComponentPtr& component) -> bool {
                     return dynamic_cast<Component_T*>(component.get());
                   });
  return found == components_.cend() ? ComponentPtr() : *found;
}

template <class... Args>
ComponentPtrs Entity::components() {
  ComponentPtrs res{component<Args>()...};
  res.erase(nullptr);
  return res;
}

template <class... Args>
EntityPtrs Entity::filter(const EntityPtrs& entities) {
  EntityPtrs res;
  std::copy_if(std::begin(entities), std::end(entities),
               std::back_inserter(res), [](const EntityPtr& entity) {
                 return ((entity->component<Args>()) && ...);
               });
  return res;
}

}  // namespace ecs

#endif  // ENTITY_H
