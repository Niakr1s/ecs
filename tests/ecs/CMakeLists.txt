cmake_minimum_required(VERSION 2.8)

find_package(GTest CONFIG REQUIRED)
enable_testing()

file(GLOB mock mock/*)

add_executable(ecs_tests
    main.cpp
    entity_tests.h
    world_tests.h
    system_tests.h
    movesystem_tests.h
    pos_tests.h
    poscomponent_tests.h
    ${mock}
)

target_link_libraries(ecs_tests
    PUBLIC ecs
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)

add_test(AllTestsInEcs ecs_tests)
