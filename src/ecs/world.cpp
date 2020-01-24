#include "world.h"

#include <iostream>

namespace ecs {

World::World() : status_(Status::INIT) {}

void World::start() {
  last_update_time_ = now();

  status_ = Status::RUNNING;
  loop();
}

void World::loop() {
  while (status_ != Status::STOPPED) {
    auto time = now();
    std::chrono::milliseconds diff = diff_time(time, last_update_time_);
    last_update_time_ = time;

    for (auto& system : systems_) {
      system->process(*this, diff);
    }
  }
}

}  // namespace ecs
