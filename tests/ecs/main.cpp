#include <gtest/gtest.h>

#include "entity_tests.h"
#include "movesystem_tests.h"
#include "pos_tests.h"
#include "poscomponent_tests.h"
#include "system_tests.h"
#include "world_tests.h"

int main(int argc, char* argv[]) {
  testing::InitGoogleMock(&argc, argv);
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
