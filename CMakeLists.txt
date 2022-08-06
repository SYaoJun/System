cmake_minimum_required(VERSION 3.21)
project(server)
# C++17编译标准
set(CMAKE_CXX_STANDARD 17)
set(ROOT_DIR ${CMAKE_SOURCE_DIR})
# 添加头文件
include_directories(include)
# 指定外部引用文件的搜索路径
link_directories(${ROOT_DIR}/lib)
# 添加源文件
aux_source_directory(${ROOT_DIR}/src DIR_SRCS)
aux_source_directory(${ROOT_DIR}/src/gtest DIR_GTEST)

# 需要编译的源文件
add_executable(server  ${DIR_GTEST} ${DIR_SRCS})
# 链接外部库
target_link_libraries(server libgtest.a libgtest_main.a)
