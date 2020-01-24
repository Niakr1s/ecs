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

  entity.setComponent(component1);
  entity.setComponent(component2);

  return {entity, component1, component2};
}

TEST(entity, setComponent1) {
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

TEST(entity, component1) {
  auto [e, c1, c2] = initEntity();

  ComponentPtr filtered = e.component<ComponentMock1>();
  ASSERT_NE(filtered, nullptr);
}

TEST(entity, component2) {
  auto [e, c1, c2] = initEntity();

  ComponentPtr filtered = e.component<ComponentMock2>();
  ASSERT_NE(filtered, nullptr);
}

TEST(entity, components0) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.components<>();
  ASSERT_EQ(filtered.size(), 0);
}

TEST(entity, components1) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.components<ComponentMock1>();
  ASSERT_EQ(filtered.size(), 1);
}

TEST(entity, components2) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.components<ComponentMock1, ComponentMock2>();
  ASSERT_EQ(filtered.size(), 2);
}

TEST(entity, components22) {
  auto [e, c1, c2] = initEntity();

  ComponentPtrs filtered = e.components<ComponentMock2, ComponentMock2>();
  ASSERT_EQ(filtered.size(), 1);
}

#endif  // COMPONENT_TESTS_H
