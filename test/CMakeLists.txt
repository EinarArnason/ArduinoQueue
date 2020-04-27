cmake_minimum_required(VERSION 3.11.0)
project(test_ArduinoQueue VERSION 0.1.0)

# Testing library
include(FetchContent)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()
FetchContent_Declare(
catch2
GIT_REPOSITORY https://github.com/catchorg/Catch2.git
GIT_TAG        v2.9.1
)
FetchContent_MakeAvailable(catch2)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_link_libraries(${PROJECT_NAME} PRIVATE ArduinoQueue Catch2::Catch2)
add_test(NAME ArduinoQueueTest COMMAND ${PROJECT_NAME})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
