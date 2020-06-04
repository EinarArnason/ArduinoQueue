cmake_minimum_required(VERSION 3.11.0)
project(test_ArduinoQueue VERSION 1.2.3)

include(FetchContent)

# Testing library
FetchContent_Declare(
catch2
GIT_REPOSITORY https://github.com/catchorg/Catch2.git
GIT_TAG        v2.9.1
)
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    FetchContent_GetProperties(catch2)
    if(NOT catch2_POPULATED)
      FetchContent_Populate(catch2)
      add_subdirectory(${catch2_SOURCE_DIR} ${catch2_BINARY_DIR})
    endif()
else()
    FetchContent_MakeAvailable(catch2)
endif()

set(TESTS test_IntQueue test_performance)
foreach(test ${TESTS})
    add_executable(${test} ${PROJECT_SOURCE_DIR}/${test}.cpp)
    target_compile_features(${test} PRIVATE cxx_std_17)
    target_link_libraries(${test} PRIVATE ArduinoQueue Catch2::Catch2)
    add_test(NAME ${test} COMMAND ${test})
endforeach(test ${TESTS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
