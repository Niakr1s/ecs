#ifndef DIRECTIONMOVECOMPONENT_H
#define DIRECTIONMOVECOMPONENT_H

#include "angle.h"
#include "ecs_time.h"
#include "movecomponent.h"
#include "speed.h"

namespace ecs {

class DirectionMoveComponent : public MoveComponent {
 public:
  DirectionMoveComponent(const Angle& angle, Speed speed);

  void move(std::shared_ptr<PosComponent> pos_component,
            std::chrono::milliseconds diff) override;

 protected:
  std::ostream& doPrint(std::ostream& out) const override;

 private:
  Angle angle_;
  Speed speed_;
};

}  // namespace ecs

#endif  // DIRECTIONMOVECOMPONENT_H
