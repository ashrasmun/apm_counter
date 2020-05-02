cmake_minimum_required(VERSION 3.14)

project(apm_counter)

set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

add_executable(
  apm_counter
  WIN32 src/main.cpp
  )
