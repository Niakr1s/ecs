#include "angle.h"

#include <cmath>
#include <iomanip>

namespace ecs {

Angle::Angle(double rad) : rad_(rad) {}

double Angle::diffX() const { return std::cos(rad_); }

double Angle::diffY() const { return std::sin(rad_); }

std::ostream &Angle::doPrint(std::ostream &out) const {
  out.setf(std::ios::fixed);
  return out << "Angle(" << std::setprecision(2) << rad_ / PI << " PI)";
}

}  // namespace ecs
