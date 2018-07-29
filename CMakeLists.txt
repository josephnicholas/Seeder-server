cmake_minimum_required(VERSION 3.10)
project(Seeder_server)

add_subdirectory("${PROJECT_SOURCE_DIR}/server" "${PROJECT_SOURCE_DIR}/server-output")
add_subdirectory("${PROJECT_SOURCE_DIR}/client" "${PROJECT_SOURCE_DIR}/client-output")
