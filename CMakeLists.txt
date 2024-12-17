#
# Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
# Unauthorized copying of this file, via any medium is strictly prohibited.
# Proprietary and confidential.
# Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
# 

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(rsd LANGUAGES C)

set(RSD_TEST_APP rsd_test1)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")
message("CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")

if(NOT CMAKE_BUILD_TYPE STREQUAL "Release")
  add_definitions(-DDEBUG=1)
endif()

include(CheckLibraryExists)
include(CheckFunctionExists)
include(CheckCCompilerFlag)
include(CheckIncludeFile)

message("CMake version: ${CMAKE_VERSION}")
message("Install path: ${CMAKE_INSTALL_PREFIX}")
message("Binary directory: ${CMAKE_BINARY_DIR}")
message("CTest binary directory: ${CTEST_BINARY_DIRECTORY}")

set(CMAKE_FIND_LIBRARY_SUFFIXES ${CMAKE_STATIC_LIBRARY_SUFFIX})

find_package(ZLIB)
if (ZLIB_FOUND)
  message("ZLIB include dir: ${ZLIB_INCLUDE_DIRS}")
  message("ZLIB libraries: ${ZLIB_LIBRARIES}")
  include_directories(BEFORE SYSTEM ${ZLIB_INCLUDE_DIRS})
  add_definitions(-DHAVE_ZLIB=1)
else()
  message("ZLIB not found")
endif()

find_package(zstd)
if (zstd_FOUND)
  message("zstd include dir: ${zstd_INCLUDE_DIRS}")
  message("zstd libraries: ${zstd_LIBRARIES}")
  include_directories(BEFORE SYSTEM ${zstd_INCLUDE_DIRS})
  add_definitions(-DHAVE_ZSTD=1)
else()
  message("zstd not found")
endif()

find_package(LibLZMA)
if (LIBLZMA_FOUND)
  message("LibLZMA include dir: ${LIBLZMA_INCLUDE_DIRS}")
  message("LibLZMA libraries: ${LIBLZMA_LIBRARIES}")
  include_directories(BEFORE SYSTEM ${LIBLZMA_INCLUDE_DIRS})
  add_definitions(-DHAVE_LIBLZMA=1)
else()
  message("LibLZMA not found")
endif()

set(RSD_TESTS_HEADERS
  rsd.h
  rsd_buff.h
  rsd_errc.h
  rsd_json.h
  rsd_logf.h
  rsd_path.h
  rsd_pid.h
)

set(RSD_TESTS_SOURCES
  tests/rsd_tests.c
)

source_group("main" FILES
  rsd.h
  rsd_buff.h
  rsd_errc.h
  rsd_json.h
  rsd_logf.h
  rsd_path.h
  rsd_pid.h
)

#TODO: check installed JSON libs, if not include bundled 'cJSON.h'
#if(...)
#list(APPEND RSD_TESTS_HEADERS "cJSON.h")
#source_group("main" FILES "cJSON.h")
#endif()

source_group("tests" FILES
  tests/rsd_tests.c
)

add_executable(${RSD_TEST_APP} ${RSD_TESTS_HEADERS} ${RSD_TESTS_SOURCES})

enable_testing()

add_test(
  NAME "All"
  COMMAND $<TARGET_FILE:${RSD_TEST_APP}>
)
