#ifndef MOVECOMPONENT_H
#define MOVECOMPONENT_H

namespace ecs {

class MoveComponent {
 public:
  virtual void move() = 0;
};

}  // namespace ecs

#endif  // MOVECOMPONENT_H
