#include "entity.h"

#include <algorithm>

namespace ecs {

Entity::Entity() {}

void Entity::addComponent(const ComponentPtr& component) {
  components_.insert(component);
}

void Entity::removeComponent(const ComponentPtr& component) {
  components_.erase(component);
}

}  // namespace ecs
