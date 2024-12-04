#
# Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
# Unauthorized copying of this file, via any medium is strictly prohibited.
# Proprietary and confidential.
# Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
# 

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(rsd LANGUAGES C)

set(RSD_TEST_APP rsd_test1)

include(CheckLibraryExists)
include(CheckFunctionExists)
include(CheckCCompilerFlag)
include(CheckIncludeFile)

message("CMake version: ${CMAKE_VERSION}")
message("Install path: ${CMAKE_INSTALL_PREFIX}")
message("Binary directory: ${CMAKE_BINARY_DIR}")
message("CTest binary directory: ${CTEST_BINARY_DIRECTORY}")

set(RSD_TESTS_HEADERS
  rsd.h
  rsd_pid.h
  rsd_errc.h
)

set(RSD_TESTS_SOURCES
  tests/rsd_tests.c
)

source_group("main" FILES
  rsd.h
  rsd_pid.h
  rsd_errc.h
)

source_group("tests" FILES
  tests/rsd_tests.c
)

add_executable(${RSD_TEST_APP} ${RSD_TESTS_HEADERS} ${RSD_TESTS_SOURCES})

enable_testing()

add_test(
  NAME "All"
  COMMAND $<TARGET_FILE:${RSD_TEST_APP}>
)
