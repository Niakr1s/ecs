#include "entity.h"

#include <algorithm>

namespace ecs {

Entity::Entity() {}

void Entity::addComponent(const ComponentPtr& component) {
  components_.push_back(component);
}

void Entity::removeComponent(const ComponentPtr& component) {
  components_.erase(
      std::remove_if(std::begin(components_), std::end(components_),
                     [&](const ComponentPtr& this_component) {
                       return component.get() == this_component.get();
                     }),
      std::end(components_));
}

}  // namespace ecs
