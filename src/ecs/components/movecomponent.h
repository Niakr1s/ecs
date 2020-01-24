#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H

#include "component.h"
#include "ecs_time.h"
#include "poscomponent.h"

namespace ecs {

class MoveComponent : public Component {
 public:
  ~MoveComponent();

  virtual void move(std::shared_ptr<PosComponent> pos_component,
                    std::chrono::milliseconds diff) = 0;
};

}  // namespace ecs

#endif  // MOVECOMPONENT_H
