cmake_minimum_required(VERSION 3.14)

project(apm_counter)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(
  apm_counter
  src/main.cpp
  )
