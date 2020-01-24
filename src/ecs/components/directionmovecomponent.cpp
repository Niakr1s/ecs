#include "directionmovecomponent.h"

namespace ecs {

DirectionMoveComponent::DirectionMoveComponent(const Angle &angle, double speed)
    : angle_(angle), speed_(speed) {}

void DirectionMoveComponent::move(std::shared_ptr<PosComponent> pos_component,
                                  std::chrono::milliseconds diff) {
  double dist = speed_ * diff.count();
  Pos diff_pos(static_cast<int>(angle_.diffX() * dist),
               static_cast<int>(angle_.diffY() * dist));
  (*pos_component) += diff_pos;
}

}  // namespace ecs
