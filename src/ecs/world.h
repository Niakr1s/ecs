#ifndef WORLD_H
#define WORLD_H

#include <chrono>
#include <iterator>

#include "ecs_time.h"
#include "entity.h"
#include "system.h"

namespace ecs {

class World {
 public:
  World();

  enum class Status { INIT, RUNNING, PAUSED, STOPPED };

  void start();

  inline void pause() { status_ = Status::PAUSED; }
  inline void unpause() { status_ = Status::RUNNING; }
  inline void stop() { status_ = Status::STOPPED; }

  inline void addEntity(const EntityPtr& entity) { entities_.insert(entity); }

  inline void addSystem(const SystemPtr& system) { systems_.insert(system); }

  template <class Entity_T>
  EntityPtr entity();

  template <class... Args>
  EntityPtrs filterByComponents();

  template <class... Args>
  EntityPtrs filterByComponents(const Entity::State& state);

 private:
  EntityPtrs entities_;
  SystemPtrs systems_;

  Status status_;
  Time_t last_update_time_;

  void loop();
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

template <class... Args>
EntityPtrs World::filterByComponents(const Entity::State& state) {
  EntityPtrs res = filterByComponents<Args...>();
  for (auto it = std::begin(res); it != std::end(res);) {
    if ((*it)->getState() != state) {
      it = res.erase(it);
    } else {
      ++it;
    }
  }
  return res;
}

}  // namespace ecs

#endif  // WORLD_H
