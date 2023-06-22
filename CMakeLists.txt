# libtuntap CMakeLists.txt
# ========================
cmake_minimum_required(VERSION 3.0)

project(libtuntap LANGUAGES CXX)
include(CTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_library(tuntap++
        bindings/cpp/tuntap++.cc
        tuntap.c
        tuntap-unix.c
        tuntap-unix-linux.c
        tuntap_log.c)

