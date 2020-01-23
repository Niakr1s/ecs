#ifndef COMPONENT_TESTS_H
#define COMPONENT_TESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity.h"
#include "mock/component_mock.h"

using namespace ecs;

std::tuple<Entity, ComponentPtr, ComponentPtr> initEntity() {
  ComponentPtr component1{new ComponentMock1()};
  ComponentPtr component2{new ComponentMock2()};

  Entity entity;

  entity.addComponent(component1);
  entity.addComponent(component2);

  return {entity, component1, component2};
}

TEST(entity, addComponent1) {
  auto [e, c1, c2] = initEntity();

  ASSERT_EQ(e.componentsSize(), 2);
}

TEST(entity, removeComponent1) {
  auto [e, c1, c2] = initEntity();

  e.removeComponent(c1);
  ASSERT_EQ(e.componentsSize(), 1);

  e.removeComponent(c2);
  ASSERT_EQ(e.componentsSize(), 0);
}

TEST(entity, filter0) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.filterComponents<>();
  ASSERT_EQ(filtered.size(), 0);
}

TEST(entity, filter1) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.filterComponents<ComponentMock1>();
  ASSERT_EQ(filtered.size(), 1);
}

TEST(entity, filter2) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.filterComponents<ComponentMock2>();
  ASSERT_EQ(filtered.size(), 1);
}

TEST(entity, filter12) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.filterComponents<ComponentMock1, ComponentMock2>();
  ASSERT_EQ(filtered.size(), 2);
}

#endif  // COMPONENT_TESTS_H
