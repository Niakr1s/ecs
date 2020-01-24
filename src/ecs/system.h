#ifndef SYSTEM_H
#define SYSTEM_H

#include <memory>
#include <vector>

#include "ecs_time.h"
#include "printable.h"

namespace ecs {

class World;

class System : public Printable {
 public:
  virtual ~System() = default;

  virtual void process(const World& world, std::chrono::milliseconds diff) = 0;
};

using SystemPtr = std::shared_ptr<System>;
using SystemPtrs = std::vector<SystemPtr>;

}  // namespace ecs

#endif  // SYSTEM_H
