cmake_minimum_required(VERSION 3.16)

add_library(GLAD gl.c)

target_link_libraries(GLAD dl)