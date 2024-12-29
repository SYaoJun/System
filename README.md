# 实用系统编程（C/C++/Rust）
- 掌握在Linux/Unix系统使用C/C++/Rust语言实现系统级项目的能力。

## 课程目标
- 构建可靠稳定的系统
- 熟悉端到端的系统设计
- 掌握性能分析，调试和优化底层代码的能力
- 理解内存，磁盘的资源管理方式
- 提高对各种需求的实际编程能力

## 优势
- ICS/OS/CA讲过的高频知识我们会再讲。
- ICS/OS/CA没讲过的工程实践我们会讲。
- 系统方向学术界和企业中用到的前沿知识会略作涉及。
- 减少大学课堂和互联网企业系统编程技术上的GAP。

## 就业价值
- 服务器编程
- 数据库系统内核
- 操作系统
- 高性能计算
- 嵌入式开发
- 游戏引擎和图形引擎开发
- 虚拟机和容器化技术
- 网络协议栈与路由器
- 后端平台工具开发
- 编译器


## 课程大纲
### 1. 系统编程
- 系统调用
- 文件IO
- 进程间通信IPC
- 多线程并发
- 网络编程
- 信号

### 2. 网络编程
- socket
- epoll
- TCP
- HTTP
- protobuf
- RPC
- RDMA

### 3. 操作系统(TBA)
- 操作系统xv6
- 汇编语言MIPS/RISC-V
- 内存虚拟化技术
- 并行优化
- 文件系统FUSE
- DPDK
- SPDK
- NVMe SSD

### 4. 工具
- ssh 远程登录
- git 版本管理
- vim 编辑器
- gcc 编译
- makefile 文件管理
- gdb 调试
- valgrind 内存泄露
- lcov 覆盖率
- clang-format 格式化代码
- netstat 查看网络连接
- tcpdump 查看网络传输
- perf 性能分析

### 5. 异步I/O
- 非阻塞I/O
- I/O多路复用epoll
- libaio
- Boost.Asio
- promise/future(C++11)
- async/await(Rust)
- io_uring
- 协程(C++20)

##  Labs
- 命令行参数解析（100行左右）
- 解析CSV文件（200行左右）
- 文件I/O（500行左右)
- 多进程系统（800行左右）
- 多线程系统（1000行左右)

## Project(TBA)
- [Sherman](https://github.com/thustorage/Sherman)
- [ShiftLock](https://github.com/thustorage/shiftlock)
- [TeRM](https://github.com/thustorage/TeRM)


## 参考书籍
- [Linux高性能服务器编程-游双](./books/Linux高性能服务器编程%20(游双　著)%20(z-lib.org).pdf)
- [CSAPP](https://csapp.cs.cmu.edu/)


## 参考课程
- CMU15-213
- CS61C
- CS110
- CS162
- CS107
- CSSE2310
- [system programming](https://github.com/ls1-sys-prog-course/docs)

## 附录
- ICS: 计算机系统导论
- OS: 操作系统
- CA: 计算机体系结构