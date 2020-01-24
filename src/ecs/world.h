#ifndef WORLD_H
#define WORLD_H

#include <iterator>

#include "entity.h"

namespace ecs {

class World {
 public:
  World();

  inline void addEntity(const EntityPtr& entity) { entities_.insert(entity); }

  template <class... Args>
  EntityPtrs filter();

 private:
  EntityPtrs entities_;
};

template <class... Args>
EntityPtrs World::filter() {
  EntityPtrs res;
  std::copy_if(std::begin(entities_), std::end(entities_),
               std::inserter(res, std::end(res)), [](const EntityPtr& entity) {
                 return ((entity->component<Args>()) && ...);
               });
  return res;
}

}  // namespace ecs

#endif  // WORLD_H
