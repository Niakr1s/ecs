#ifndef WORLD_H
#define WORLD_H

#include <iterator>

#include "entity.h"

namespace ecs {

class World {
 public:
  World();

  inline void addEntity(const EntityPtr& entity) { entities_.insert(entity); }

  template <class Entity_T>
  EntityPtr entity();

  template <class... Args>
  EntityPtrs filterByComponents();

 private:
  EntityPtrs entities_;
};

template <class Entity_T>
EntityPtr World::entity() {
  auto found = std::find_if(std::cbegin(entities_), std::cend(entities_),
                            [](const EntityPtr& entity) {
                              return dynamic_cast<Entity_T*>(entity.get());
                            });
  return (found == std::cend(entities_)) ? nullptr : *found;
}

template <class... Args>
EntityPtrs World::filterByComponents() {
  EntityPtrs res;
  std::copy_if(std::begin(entities_), std::end(entities_),
               std::inserter(res, std::end(res)), [](const EntityPtr& entity) {
                 return ((entity->component<Args>()) && ...);
               });
  return res;
}

}  // namespace ecs

#endif  // WORLD_H
