#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "ecs_time.h"
#include "system.h"

namespace ecs {

class MoveSystem : public System {
 public:
  MoveSystem();

  void process(const World& world, Time_diff_ns_t diff_ns);
};

}  // namespace ecs

#endif  // MOVESYSTEM_H
