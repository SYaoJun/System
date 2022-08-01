## C++工程实践
- 功能
- 安全
- 三高
  - 高并发
  - 高可用
  - 高性能
### 目录结构
- build
- include
- src
- docs
- others
### CMakeLists.txt
- 类似于maven，用来管理源文件和依赖。
- xxx.so和xxx.a
- 在链接的时候，把这些依赖的文件跟当前的文件，合并到一起。

### 编译
- 针对Linux/MacOS
```shell
cd build
cmake ..
./server
```
### 注意
- 不要使用`using namespace std`，可能存在同名冲突。
- 尽量使用列表初始化构造函数，性能更好，具体原因参考effective c++

### 常用
- 多态
- 拷贝构造
- 赋值构造
- 传值
- 传引用
- 智能指针
- 字符串
- new
- thread
- vector
- map/unordered_map/set
- pair
- bitset
- 高精度时间chrono
- sort
- mutex
- 模板
- tuple
### 字节序
- 主机字节序（现代PC）小端little endian
- 网络字节序（JAVA虚拟机）大端big endian
  - 一个整数的高位字节23~31bit，存储在内存的低地址处
  - 低位字节0~7bit，存储在内存的高地址处。
- 记法：小端字节序——低存低，高存高。12345678存储，12存在0x8f, 34存在0x6f, 56存在0x4f, 78存在0x2f。
### 高效IO读写函数（零拷贝技术）
- sendfile
- mmap
- splice
- tee
### 调测
- tcpdump抓包
- strace跟踪程序运行时执行的系统调用和接收到的信号
- netstat网络接口统计
- vmstat系统资源统计
- top
### web服务器关键技术点
> 参考书籍：《Linux高性能服务器编程》游双
- 线程池
- epoll使用
- 定时器/任务调度策略/多核多备份的调度/分布式数据一致性
### 进阶问题
- 你为什么要这样设计？
- 他的优点和缺点分别是什么？
- 你从项目中获得了哪些成长？
### 单例模式
- 构造函数私有
- 实例只有一份
### 工厂模式
- 一个类别对应一个工厂
- 不需要亲自创建对象，只需要从工厂中去取。

