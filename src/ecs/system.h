#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include <set>

#include "ecs_time.h"

namespace ecs {

class World;

class System {
 public:
  virtual ~System() = default;

  virtual void process(const World& world, Time_diff_ns_t diff_ns) = 0;
};

using SystemPtr = std::shared_ptr<System>;
using SystemPtrs = std::set<SystemPtr>;

}  // namespace ecs

#endif  // SYSTEM_H
