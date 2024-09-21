# backend/CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(my_backend)

set(CMAKE_CXX_STANDARD 17)
find_package(PQ REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(${PQ_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIRS})

add_executable(my_backend main.cpp Database.cpp endpoints.cpp)
target_link_libraries(my_backend ${PQ_LIBRARIES} ${Boost_LIBRARIES})
