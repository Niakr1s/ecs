#ifndef MOVESYSTEM_H
#define MOVESYSTEM_H

#include "ecs_time.h"
#include "system.h"

namespace ecs {

class MoveSystem : public System {
 public:
  MoveSystem();

  void process(const World& world, std::chrono::milliseconds diff);

 protected:
  std::ostream& doPrint(std::ostream& out) const override;
};

}  // namespace ecs

#endif  // MOVESYSTEM_H
