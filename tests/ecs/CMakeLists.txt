cmake_minimum_required(VERSION 2.8)

find_package(GTest CONFIG REQUIRED)
enable_testing()

file(GLOB ecs_tests_src
    *.cpp *.h
    mock/*.cpp mock/*.h
)

add_executable(ecs_tests
    ${ecs_tests_src}
)

target_link_libraries(ecs_tests
    PUBLIC ecs
    PRIVATE GTest::gtest GTest::gtest_main GTest::gmock GTest::gmock_main
)

add_test(AllTestsInEcs ecs_tests)
