cmake_minimum_required(VERSION 3.14)

project(Mahiru LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

# thirdparty : glog & googletest
add_subdirectory(thirdparty/glog)
add_subdirectory(thirdparty/googletest)

# thirdparty : LLVM
include(cmake/findLLVM.cmake)

add_subdirectory(mahiru/front)

add_executable(main mahiru/main.cc)
add_executable(test_isspace mahiru/test_isspace.cc)