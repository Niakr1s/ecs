#ifndef WORLD_TESTS_H
#define WORLD_TESTS_H

#include <gtest/gtest.h>

#include "entity.h"
#include "mock/component_mock.h"
#include "mock/entity_mock.h"
#include "world.h"

using namespace ecs;

TEST(world, filterByComponents1) {
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

  EntityPtrs f1 = w.filterByComponents<ComponentMock1>();
  EntityPtrs f2 = w.filterByComponents<ComponentMock2>();
  EntityPtrs f12 = w.filterByComponents<ComponentMock1, ComponentMock2>();

  ASSERT_EQ(f1.size(), 2);
  ASSERT_EQ(f2.size(), 2);
  ASSERT_EQ(f12.size(), 1);
}

TEST(world, filterByComponents2) {
  EntityPtr e12 = EntityPtr(new Entity());
  e12->setComponent<ComponentMock1>();
  e12->setComponent<ComponentMock2>();

  World w;
  w.addEntity(e12);

  EntityPtrs f_active = w.filterByComponents<ComponentMock1, ComponentMock2>(
      Entity::State::ACTIVE);
  ASSERT_EQ(f_active.size(), 1);

  EntityPtrs f_disabled = w.filterByComponents<ComponentMock1, ComponentMock2>(
      Entity::State::DISABLED);
  ASSERT_EQ(f_disabled.size(), 0);

  e12->setState(Entity::State::DEAD);
  EntityPtrs f_dead =
      w.filterByComponents<ComponentMock1, ComponentMock2>(Entity::State::DEAD);
  ASSERT_EQ(f_dead.size(), 1);
}

TEST(world, entity1) {
  EntityPtr e = EntityPtr(new EntityMock1());

  e->setComponent<ComponentMock1>();
  e->setComponent<ComponentMock2>();

  World w;

  w.addEntity(e);

  EntityPtr found1 = w.entity<EntityMock1>();
  ASSERT_EQ(found1, e);

  EntityPtr found2 = w.entity<EntityMock2>();
  ASSERT_EQ(found2, nullptr);
}

#endif  // WORLD_TESTS_H
