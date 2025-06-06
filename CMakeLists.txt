cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)


add_executable(handmade-grep 
        src/main.cpp
)
target_include_directories(handmade-grep PRIVATE include)
