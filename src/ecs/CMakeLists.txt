cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB ecs_src
    *.cpp *.h
    util/*.cpp util/*.h
    systems/*.cpp systems/*.h
    entities/*.cpp entities/*.h
    components/*.cpp components/*.h
)

add_library(ecs SHARED
    ${ecs_src}
)

target_include_directories(ecs
    PUBLIC
    .
    util

    PRIVATE
    entities
    systems
    components
)

target_compile_definitions(ecs PRIVATE ECS_LIBRARY)
