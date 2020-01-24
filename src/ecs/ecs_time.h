#ifndef ECS_TIME_H
#define ECS_TIME_H

#include <chrono>

namespace ecs {

using Time_t = std::chrono::time_point<std::chrono::high_resolution_clock>;

inline Time_t now() { return std::chrono::high_resolution_clock::now(); }

using Time_diff_ns_t = decltype(now() - now());

}  // namespace ecs

#endif  // ECS_TIME_H
