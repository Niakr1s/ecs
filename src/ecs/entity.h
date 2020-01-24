#ifndef ENTITY_H
#define ENTITY_H

#include <algorithm>
#include <set>

#include "component.h"

namespace ecs {

class Entity;

using EntityPtr = std::shared_ptr<Entity>;
using EntityPtrs = std::set<EntityPtr>;

class Entity {
 public:
  Entity();
  virtual ~Entity();

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

 protected:
  ComponentPtrs components_;
};

template <class Component_T>
bool Entity::componentExists() {
  return !(component<Component_T>() == nullptr);
}

template <class Component_T, class... Args>
void Entity::setComponent(Args... args) {
  removeComponent<Component_T>();
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

}  // namespace ecs

#endif  // ENTITY_H
