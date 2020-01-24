#include "speed.h"

#include <iomanip>

namespace ecs {

Speed::Speed(double pixels_per_second)
    : pixels_per_second_(pixels_per_second) {}

double Speed::distance(const std::chrono::seconds &seconds) {
  return pixels_per_second_ * seconds.count();
}

double Speed::distance(const std::chrono::milliseconds &milliseconds) {
  return pixels_per_millisecond() * milliseconds.count();
}

std::ostream &Speed::doPrint(std::ostream &out) const {
  out.setf(std::ios::fixed);
  return out << "Speed(" << std::setprecision(1) << pixels_per_second_
             << " pps)";
}

double Speed::pixels_per_millisecond() const {
  return pixels_per_second_ / 1000;
}

}  // namespace ecs
