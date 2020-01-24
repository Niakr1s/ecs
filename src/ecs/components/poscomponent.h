#ifndef POSCOMPONENT_H
#define POSCOMPONENT_H

#include "component.h"
#include "pos.h"

namespace ecs {

class PosComponent : public Component {
 public:
  PosComponent(int x, int y);
  PosComponent(const Pos& pos);

  Pos pos() const;

  void operator=(const Pos& rhs);
  void operator=(const PosComponent& rhs);

  void operator+=(const Pos& rhs);
  void operator+=(const PosComponent& rhs);

  void operator-=(const Pos& rhs);
  void operator-=(const PosComponent& rhs);

  bool operator==(const Pos& rhs) const;
  bool operator==(const PosComponent& rhs) const;

 private:
  Pos pos_;
};

}  // namespace ecs

#endif  // POSCOMPONENT_H
