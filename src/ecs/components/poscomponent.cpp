#include "poscomponent.h"

namespace ecs {

PosComponent::PosComponent(int x, int y) : PosComponent(Pos(x, y)) {}

PosComponent::PosComponent(const Pos &pos) : pos_(pos) {}

Pos PosComponent::pos() const { return pos_; }

void PosComponent::operator=(const Pos &rhs) { pos_ = rhs; }

void PosComponent::operator=(const PosComponent &rhs) { *this = rhs.pos(); }

void PosComponent::operator+=(const Pos &rhs) { pos_ += rhs; }

void PosComponent::operator+=(const PosComponent &rhs) { *this += rhs.pos(); }

void PosComponent::operator-=(const Pos &rhs) { pos_ -= rhs; }

void PosComponent::operator-=(const PosComponent &rhs) { *this -= rhs.pos(); }

bool PosComponent::operator==(const Pos &rhs) const { return pos_ == rhs; }

bool PosComponent::operator==(const PosComponent &rhs) const {
  return pos_ == rhs.pos_;
}

}  // namespace ecs
