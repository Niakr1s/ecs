#ifndef ECS_TIME_H
#define ECS_TIME_H

#include <chrono>

namespace ecs {

using Time_t = std::chrono::time_point<std::chrono::high_resolution_clock>;

inline Time_t now() { return std::chrono::high_resolution_clock::now(); }

inline std::chrono::milliseconds diff_time(const Time_t& start,
                                           const Time_t& end) {
  return std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
}

}  // namespace ecs

#endif  // ECS_TIME_H
