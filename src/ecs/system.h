#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include <set>

namespace ecs {

class World;

class System {
 public:
  virtual ~System() = default;

  virtual void process(const World& world) = 0;
};

using SystemPtr = std::shared_ptr<System>;
using SystemPtrs = std::set<SystemPtr>;

}  // namespace ecs

#endif  // SYSTEM_H
