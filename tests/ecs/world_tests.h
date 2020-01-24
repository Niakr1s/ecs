#ifndef WORLD_TESTS_H
#define WORLD_TESTS_H

#include <gtest/gtest.h>

#include "entity.h"
#include "world.h"

using namespace ecs;

TEST(world, filter1) {
  EntityPtr e1 = EntityPtr(new Entity());
  EntityPtr e2 = EntityPtr(new Entity());
  EntityPtr e12 = EntityPtr(new Entity());

  e1->setComponent<ComponentMock1>();

  e2->setComponent<ComponentMock2>();

  e12->setComponent<ComponentMock1>();
  e12->setComponent<ComponentMock2>();

  World w;

  w.addEntity(e1);
  w.addEntity(e2);
  w.addEntity(e12);

  EntityPtrs f1 = w.filter<ComponentMock1>();
  EntityPtrs f2 = w.filter<ComponentMock2>();
  EntityPtrs f12 = w.filter<ComponentMock1, ComponentMock2>();

  ASSERT_EQ(f1.size(), 2);
  ASSERT_EQ(f2.size(), 2);
  ASSERT_EQ(f12.size(), 1);
}

#endif  // WORLD_TESTS_H
