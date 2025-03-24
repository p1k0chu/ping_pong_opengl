cmake_minimum_required(VERSION 3.31)
project("ping_pong_opengl")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Og")

include_directories(include)

add_executable(PingPong main.cpp)
