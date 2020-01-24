#include "pos.h"

namespace ecs {

Pos::Pos(int x, int y) : x_(x), y_(y) {}

Pos Pos::operator+(const Pos &rhs) const {
  Pos res(*this);
  res.x_ += rhs.x_;
  res.y_ += rhs.y_;
  return res;
}

void Pos::operator+=(const Pos &rhs) { *this = *this + rhs; }

Pos Pos::operator-(const Pos &rhs) const {
  Pos res(*this);
  res.x_ -= rhs.x_;
  res.y_ -= rhs.y_;
  return res;
}

void Pos::operator-=(const Pos &rhs) { *this = *this - rhs; }

bool Pos::operator==(const Pos &rhs) const {
  return (x_ == rhs.x_ && y_ == rhs.y_);
}

}  // namespace ecs
