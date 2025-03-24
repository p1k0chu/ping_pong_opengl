cmake_minimum_required(VERSION 3.31)
project("ping_pong_opengl")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Og")

find_library(GL_LIB GL)
find_library(GLFW_LIB glfw)

include_directories(include)

add_library(glad glad.c)

add_executable(PingPong
    main.cpp
    shader.cpp
)

target_link_libraries(PingPong
    PRIVATE
    glad
    "${GL_LIB}"
    "${GLFW_LIB}"
)
