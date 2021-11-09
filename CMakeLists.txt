cmake_minimum_required(VERSION 3.10.0)
project(
  coding-interview
  VERSION 0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/16f637fbf4ffc3f7a01fa4eceb7906634565242f.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/sources")
file(GLOB_RECURSE TEST_FILES "tests/*.test.cc")
foreach(TEST_FILE ${TEST_FILES})
  get_filename_component(EXECUTABLE_FILE ${TEST_FILE} NAME_WE)
  set(EXECUTABLE_FILE "Test_${EXECUTABLE_FILE}")
  add_executable(${EXECUTABLE_FILE} ${TEST_FILE})
  target_link_libraries(${EXECUTABLE_FILE} gtest_main)
  include(GoogleTest)
  gtest_discover_tests(${EXECUTABLE_FILE})
endforeach(TEST_FILE ${TEST_FILES})
