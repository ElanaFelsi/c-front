cmake_minimum_required(VERSION 3.14)
project(c_UTH C)

set(CMAKE_C_STANDARD 90)

add_executable(c_UTH cpp2c_encapsulation_defs.h cpp2c_encapsulation_defs.c cpp2c_encapsulation.c cpp2c_inheritance_defs.h cpp2c_inheritance_defs.c cpp2c_inheritance.c)