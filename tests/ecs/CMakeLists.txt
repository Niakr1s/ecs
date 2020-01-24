cmake_minimum_required(VERSION 2.8)

enable_testing()
find_package(GTest REQUIRED)

file(GLOB mock mock/*)

add_executable(ecs_tests
    main.cpp
    entity_tests.h
    world_tests.h
    ${mock}
)

target_link_libraries(ecs_tests
    ecs
    GTest::Main
)
