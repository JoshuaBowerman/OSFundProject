cmake_minimum_required(VERSION 3.9)
project(OSFundProject C)

set(CMAKE_C_STANDARD 99)

add_executable(OSFundProject main.c globals.h macros.h ptable.h)