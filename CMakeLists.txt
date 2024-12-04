#
# Copyright (C) Oleh Kulykov <olehkulykov@gmail.com>. All Rights Reserved.
# Unauthorized copying of this file, via any medium is strictly prohibited.
# Proprietary and confidential.
# Created by Oleh Kulykov <olehkulykov@gmail.com>, 2024.
# 

cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(rsd LANGUAGES C)

set(RSD_TEST_APP_1 rsd_test1)

include(CheckLibraryExists)
include(CheckFunctionExists)
include(CheckCCompilerFlag)
include(CheckIncludeFile)

message("CMake version: ${CMAKE_VERSION}")
message("Install path: ${CMAKE_INSTALL_PREFIX}")
message("Binary directory: ${CMAKE_BINARY_DIR}")
message("CTest binary directory: ${CTEST_BINARY_DIRECTORY}")

check_c_compiler_flag("-fPIC" WITH_FPIC_C)
if (WITH_FPIC_C)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
endif()

set(RSD_TESTS_HEADERS)

set(RSD_TESTS_SOURCES
  rsd_tests.c
)

source_group("main" FILES
  rsd_tests.c
)

add_executable(${RSD_TEST_APP_1} ${RSD_TESTS_HEADERS} ${RSD_TESTS_SOURCES})

enable_testing()

add_test(
  NAME "NoArgsShowHelp"
  COMMAND $<TARGET_FILE:${RSD_TEST_APP_1}>
)

add_test(
  NAME "SelfProcess"
  COMMAND $<TARGET_FILE:${RSD_TEST_APP_1}> -dnwr $<TARGET_FILE:${RSD_TEST_APP_1}>
)
