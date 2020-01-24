#ifndef DIRECTIONMOVECOMPONENT_H
#define DIRECTIONMOVECOMPONENT_H

#include "angle.h"
#include "ecs_time.h"
#include "movecomponent.h"

namespace ecs {

class DirectionMoveComponent : public MoveComponent {
 public:
  DirectionMoveComponent(const Angle& angle, double speed);

  void move(std::shared_ptr<PosComponent> pos_component,
            Time_diff_ns_t diff_ns) override;

 private:
  Angle angle_;
  double speed_;
};

}  // namespace ecs

#endif  // DIRECTIONMOVECOMPONENT_H
