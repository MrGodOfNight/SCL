cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME SCL)
project(${PROJECT_NAME})

file(GLOB MY_SOURCE_FILES "../modules/*/*.cpp" "../modules/*/*.hpp")

set(SOURCES
  main.cpp
  ${MY_SOURCE_FILES}
)

add_executable(main ${SOURCES})