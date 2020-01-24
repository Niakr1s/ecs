#include "angle.h"

#include <cmath>

namespace ecs {

Angle::Angle(double degree) : degree_(degree) {}

double Angle::diffX() const { return std::cos(degree_); }

double Angle::diffY() const { return std::sin(degree_); }

}  // namespace ecs
