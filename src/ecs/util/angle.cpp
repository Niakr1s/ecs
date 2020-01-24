#include "angle.h"

#include <cmath>
#include <iomanip>

namespace ecs {

Angle::Angle(double rad) : rad_(rad) {}

Angle Angle::fromRadians(double rad) { return Angle(rad); }

Angle Angle::fromDegrees(double deg) { return Angle(deg / 180 * PI); }

Angle Angle::fromPi(double pi_multiplier) { return Angle(pi_multiplier * PI); }

double Angle::diffX() const { return std::cos(rad_); }

double Angle::diffY() const { return std::sin(rad_); }

std::ostream &Angle::doPrint(std::ostream &out) const {
  out.setf(std::ios::fixed);
  return out << "Angle(" << std::setprecision(2) << rad_ / PI << " PI)";
}

Angle angle_literals::operator"" _rad(long double rad) {
  return Angle::fromRadians(rad);
}

Angle angle_literals::operator"" _deg(long double deg) {
  return Angle::fromDegrees(deg);
}

Angle angle_literals::operator"" _pi(long double pi_multiplier) {
  return Angle::fromPi(pi_multiplier);
}

}  // namespace ecs
