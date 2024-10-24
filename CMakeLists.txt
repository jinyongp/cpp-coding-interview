cmake_minimum_required(VERSION 3.14.0)
cmake_policy(SET CMP0063 NEW)
project(
  coding-interview
  VERSION 0.1
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b514bdc898e2951020cbdca1304b75f5950d1f59.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

include_directories("${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE TEST_FILES "src/*.test.cpp")
foreach(TEST_FILE ${TEST_FILES})
  get_filename_component(EXECUTABLE_FILE ${TEST_FILE} NAME_WE)
  set(EXECUTABLE_FILE "Test_${EXECUTABLE_FILE}")

  add_executable(${EXECUTABLE_FILE} ${TEST_FILE})
  target_link_libraries(${EXECUTABLE_FILE} gtest_main)

  include(GoogleTest)
  gtest_discover_tests(
    ${EXECUTABLE_FILE}
    EXTRA_ARGS --gtest_brief=1
  )
endforeach(TEST_FILE ${TEST_FILES})
