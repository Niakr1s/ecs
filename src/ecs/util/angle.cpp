#include "angle.h"

#include <cmath>
#include <iomanip>

namespace ecs {

Angle::Angle(double degree) : degree_(degree) {}

double Angle::diffX() const { return std::cos(degree_); }

double Angle::diffY() const { return std::sin(degree_); }

std::ostream &Angle::doPrint(std::ostream &out) const {
  out.setf(std::ios::fixed);
  return out << "Angle(" << std::setprecision(2) << degree_ / PI << " PI)";
}

}  // namespace ecs
