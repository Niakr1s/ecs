#include "movesystem.h"

#include "components.h"
#include "world.h"

namespace ecs {

MoveSystem::MoveSystem() {}

void MoveSystem::process(const World& world, Time_diff_ns_t diff_ns) {
  auto entities = world.filterByComponents<PosComponent, MoveComponent>();

  for (auto& entity : entities) {
    auto move_component = entity->component<MoveComponent>();
    auto pos_component = entity->component<PosComponent>();

    move_component->move(pos_component, diff_ns);
  }
}

}  // namespace ecs
