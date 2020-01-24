#ifndef SPEED_H
#define SPEED_H

#include <chrono>

namespace ecs {

class Speed {
 public:
  Speed(double pixels_per_second);

  double distance(const std::chrono::seconds& seconds);
  double distance(const std::chrono::milliseconds& milliseconds);

 private:
  double pixels_per_second_;

  double pixels_per_millisecond() const;
};

}  // namespace ecs

#endif  // SPEED_H
