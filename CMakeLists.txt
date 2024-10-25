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
include(GoogleTest)
# enable_testing()

include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/src/*.test.cc)
add_executable(main ${TEST_FILES})
target_link_libraries(main gtest_main)
foreach(TEST_FILE ${TEST_FILES})
  get_filename_component(EXECUTABLE_FILE ${TEST_FILE} NAME_WE)
  set(EXECUTABLE_FILE ${EXECUTABLE_FILE}+test)
  add_executable(${EXECUTABLE_FILE} ${TEST_FILE})
  target_link_libraries(${EXECUTABLE_FILE} gtest_main)
endforeach(TEST_FILE ${TEST_FILES})
