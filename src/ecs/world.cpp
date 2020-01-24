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
    Time_diff_ns_t diff_ns = time - last_update_time_;
    last_update_time_ = time;

    for (auto& system : systems_) {
      system->process(*this, diff_ns);
    }
  }
}

}  // namespace ecs
