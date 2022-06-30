cmake_minimum_required(VERSION 3.22)
project(btree)

set(CMAKE_CXX_STANDARD 23)

add_executable(btree main.cpp btreeContainer.h Models.h)
