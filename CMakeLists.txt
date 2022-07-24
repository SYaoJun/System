cmake_minimum_required(VERSION 3.21)
project(server)
# C++17编译标准
set(CMAKE_CXX_STANDARD 17)
# 添加头文件
include_directories(include)
# 添加源文件
aux_source_directory(./src DIR_SRCS)
# 需要编译的源文件
add_executable(server ${DIR_SRCS})
