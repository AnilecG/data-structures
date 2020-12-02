cmake_minimum_required(VERSION 3.16)

project (bst)

add_library(bst-lib 
    bst.hh
    bst.cc)

add_executable(bst main.cc)

target_link_libraries(bst bst-lib)