cmake_minimum_required(VERSION 3.0.0)
project(ArduinoQueue VERSION 1.2.3)

include(CTest)
enable_testing()

add_subdirectory(${PROJECT_SOURCE_DIR}/test)

add_library(ArduinoQueue INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE ${PROJECT_SOURCE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
