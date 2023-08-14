
## 一个简单的web服务器

## 注意
- `epoll`是Linux系统函数，在Windows和MacOS都是无法运行的。
## 核心流程
- 服务端创建`epoll`对象，`epoll_create()`
- 服务端创建监听`socket`，将其添加`epoll_ctl()`到`epoll`等待队列
- 循环中调用`epoll_wait()`阻塞等待客户端连接
- 当新连接到达时，创建一个新的`socket`，将其添加到`epoll`等待队列
- 当`epoll_wait()`解除阻塞时，根据读写事件，调用对应的worker线程进行处理（这里没有worker）

## 编译
```
make
```
## 运行
```
./server 9999 /home/web
```