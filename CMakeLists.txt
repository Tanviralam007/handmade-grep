cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

# collect all source files
file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(handmade-grep 
        ${SOURCE_FILES}
)
target_include_directories(handmade-grep PRIVATE include)
