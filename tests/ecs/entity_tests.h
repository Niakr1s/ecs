#ifndef COMPONENT_TESTS_H
#define COMPONENT_TESTS_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "entity.h"
#include "mock/component_mock.h"

using namespace ecs;

Entity makeEntity12() {
  Entity e;

  e.setComponent<ComponentMock1>();
  e.setComponent<ComponentMock2>();

  return e;
}

TEST(entity, componentExists1) {
  Entity e = makeEntity12();

  ASSERT_TRUE(e.componentExists<ComponentMock1>());
  ASSERT_TRUE(e.componentExists<ComponentMock2>());
  ASSERT_FALSE(e.componentExists<ComponentMock3>());
}

TEST(entity, setComponent1) {
  Entity e = makeEntity12();
  ASSERT_EQ(e.componentsSize(), 2);

  e.setComponent<ComponentMock1>();
  ASSERT_EQ(e.componentsSize(), 2);
}

TEST(entity, removeComponent1) {
  Entity e = makeEntity12();

  e.removeComponent<ComponentMock1>();
  ASSERT_EQ(e.componentsSize(), 1);

  e.removeComponent<ComponentMock1>();
  ASSERT_EQ(e.componentsSize(), 1);

  e.removeComponent<ComponentMock2>();
  ASSERT_EQ(e.componentsSize(), 0);

  e.removeComponent<ComponentMock2>();
  ASSERT_EQ(e.componentsSize(), 0);
}

TEST(entity, component1) {
  Entity e = makeEntity12();

  ComponentPtr filtered = e.component<ComponentMock1>();
  ASSERT_NE(filtered, nullptr);
}

TEST(entity, component2) {
  Entity e = makeEntity12();

  ComponentPtr filtered = e.component<ComponentMock2>();
  ASSERT_NE(filtered, nullptr);
}

TEST(entity, components0) {
  Entity e = makeEntity12();

  ComponentPtrs filtered = e.components<>();
  ASSERT_EQ(filtered.size(), 0);
}

TEST(entity, components1) {
  Entity e = makeEntity12();

  ComponentPtrs filtered = e.components<ComponentMock1>();
  ASSERT_EQ(filtered.size(), 1);
}

TEST(entity, components2) {
  Entity e = makeEntity12();

  ComponentPtrs filtered = e.components<ComponentMock1, ComponentMock2>();
  ASSERT_EQ(filtered.size(), 2);
}

TEST(entity, components22) {
  Entity e = makeEntity12();

  ComponentPtrs filtered = e.components<ComponentMock2, ComponentMock2>();
  ASSERT_EQ(filtered.size(), 1);
}

#endif  // COMPONENT_TESTS_H
