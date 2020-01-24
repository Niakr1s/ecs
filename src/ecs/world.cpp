#include "world.h"

namespace ecs {

World::World() {}

void World::nextFrame() {
  for (auto& system : systems_) {
    system->process(*this);
  }
}

}  // namespace ecs
