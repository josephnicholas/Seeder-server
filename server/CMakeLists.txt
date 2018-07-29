cmake_minimum_required(VERSION 3.10)
project(server)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.65.1 COMPONENTS system filesystem REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
    message(STATUS "Boost_LIBRARY: ${Boost_LIBRARIES}")
    message(STATUS "Boost_VERSION: ${Boost_VERSION}")

    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_executable(server server.cpp)

if(Boost_FOUND)
    target_link_libraries(server ${Boost_LIBRARIES})
endif()