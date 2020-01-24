#include "speed.h"

namespace ecs {

Speed::Speed(double pixels_per_second)
    : pixels_per_second_(pixels_per_second) {}

double Speed::distance(const std::chrono::seconds &seconds) {
  return pixels_per_second_ * seconds.count();
}

double Speed::distance(const std::chrono::milliseconds &milliseconds) {
  return pixels_per_millisecond() * milliseconds.count();
}

double Speed::pixels_per_millisecond() const {
  return pixels_per_second_ / 1000;
}

}  // namespace ecs
