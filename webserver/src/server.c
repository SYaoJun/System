#include <arpa/inet.h>
#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#define SERV_PORT 9999
#define MAXSIZE 2048

#define EXIT_IF_RETURN_ERR(res)                                                \
  do {                                                                         \
    \       
        if (res == -1) {                                                       \
      exit(1)                                                                  \
    }                                                                          \
  } while (0)

// 获取一行\r\n结尾的数据
int get_line(int cfd, char *buf, int size) {
  int i = 0;
  char c = '\0';
  int n;
  // 当数据小于缓冲区 同时临时字符不为换行符时 循环执行
  while ((i < size - 1) && (c != '\n')) { // c只是一个临时的字符

    n = recv(cfd, &c, 1, 0); // 每次读一个字符
    if (n > 0) {
      if (c == '\r') {
        n = recv(cfd, &c, 1, MSG_PEEK); // 拷贝读一次 读完之后缓冲区还有
        if ((n > 0) && (c == '\n')) { // /r/n在linux系统中只用/n表示
          recv(cfd, &c, 1, 0);
        } else {
          c = '\n';
        }
      }
      buf[i] = c;
      i++;
    } else {
      c = '\n';
    }
  }
  buf[i] = '\0';
  if (-1 == n) // 没有数据返回-1
    i = n;
  return i;
}
// 断开连接
void disconnect(int cfd, int epfd) {
  int ret = epoll_ctl(epfd, EPOLL_CTL_DEL, cfd, NULL);
  if (ret != 0) {
    perror("epoll_cnl delete error");
    exit(1);
  }
  close(cfd);
}
// 发送服务器本地文件到客户端
void send_file(int cfd, const char *file) {
  // fd打开本地的文件
  int fd = open(file, O_RDONLY);
  if (fd == -1) { // 404 错误页面
    perror("file open error");
    exit(1);
  }
  int n, ret = 0;
  char buf[MAXSIZE] = {0};
  while ((n = read(fd, buf, sizeof(buf))) > 0) {
    ret = send(cfd, buf, n, 0);
    if (ret == -1) {
      if (errno == EAGAIN || errno == EINTR)
        continue;
      else {
        perror("send error");
        exit(1);
      }
    }
  }
  close(fd);
}
// 应答http 客户端文件描述符 状态号 状态描述 文本类型 文件长度
void send_respond(int cfd, int no, char *disp, char *type, int len) {
  int ret;
  char buf[MAXSIZE] = {0};
  sprintf(buf, "HTTP/1.1 %d %s\r\n", no, disp);
  sprintf(buf + strlen(buf), "%s\r\n", type);
  sprintf(buf + strlen(buf), "Content-Length:%d\r\n\r\n", len);

  do {
    ret = send(cfd, buf, strlen(buf), 0) > 0;
    if (ret == -1) {
      if (errno == EAGAIN || errno == EINTR)
        continue;
      else {
        perror("send error");
        exit(1);
      }
    }
  } while (0);
}
const char *get_file_type(const char *name) {
  char *dot;
  dot = strrchr(name, '.');
  if (strcmp(dot, ".jpg") == 0 || strcmp(dot, "jpeg") == 0 ||
      strcmp(dot, ".ico") == 0)
    return "image/jpeg";
  if (strcmp(dot, ".gif") == 0)
    return "image/gif";
  if (strcmp(dot, ".png") == 0)
    return "image/png";
  if (strcmp(dot, ".css") == 0)
    return "text/css";
  if (strcmp(dot, ".au") == 0)
    return "audio/basic";
  if (strcmp(dot, ".wav") == 0)
    return "audio/wav";
  if (strcmp(dot, ".avi") == 0)
    return "video/x-msvideo";
  if (strcmp(dot, ".mp3") == 0)
    return "audio/mpeg";
  return "text/html; charset=utf-8";
}
// 详细处理目录
void send_dir(int cfd, const char *dirname) {
  int i, ret;
  char buf[MAXSIZE] = {0};
  sprintf(buf, "<html><head><title>目录名:%s</title></head>", dirname);
  sprintf(buf + strlen(buf), "<body><h3>当前目录:%s</h3><table>", dirname);
  // char enstr[1024] = {0};
  char path[1024] = {0};
  // 目录项二级指针
  struct dirent **ptr;
  int num = scandir(dirname, &ptr, NULL, alphasort);
  // 遍历
  for (i = 2; i < num; i++) {
    char *name = ptr[i]->d_name;
    // 拼接文件的完整路径
    sprintf(path, "%s/%s", dirname, name);
    struct stat stt;
    stat(path, &stt);
    // encode_str(enstr, sizeof(enstr), name);  //编码中文字符
    if (S_ISREG(stt.st_mode)) { // 生成超链接
      sprintf(buf + strlen(buf),
              "<tr><td> <a href=\"%s\">%s</a>  </td><td>%ld</td></tr>", name,
              name, (long)stt.st_size);
    } else if (S_ISDIR(stt.st_mode)) {
      sprintf(buf + strlen(buf),
              "<tr><td> <a href=\"%s/\">%s</a>  </td><td>%ld</td></tr>", name,
              name, (long)stt.st_size);
    }
  }
  sprintf(buf + strlen(buf), "</body></html>%s", "");
  // 判断返回值
  send(cfd, buf, strlen(buf), 0);
  memset(buf, 0, sizeof(buf));
}
// 详细处理http
void http_request(int cfd, const char *file) {
  struct stat st;
  int ret = stat(file, &st);

  if (ret == -1) {
    // 回发浏览器404错误页面
    send_respond(cfd, 404, "FAIL", "Content-Type: text/html; charset=utf-8",
                 -1);
    send_file(cfd, "404.html");
    perror("file exist error 404 ");
    return;
  }

  if (S_ISREG(st.st_mode)) { // 是一个普通文件
    // 回发 http协议应答 回发浏览器内容
    //  printf("This a regular file!\n");

    char buf[MAXSIZE] = {0};
    const char *content_type = get_file_type(file);
    sprintf(buf, "Content-Type: %s", content_type);
    send_respond(cfd, 200, "OK", buf, -1);
    send_file(cfd, file);
  } else if (S_ISDIR(st.st_mode)) {
    send_respond(cfd, 200, "OK", "Content-Type: text/html; charset=utf-8", -1);
    send_dir(cfd, file);
  }
}

// 处理浏览器发来的http协议请求 readline \r\n
void do_read(int cfd, int epfd) {
  char line[MAXSIZE] = {0};
  do {
    int ret = get_line(cfd, line, sizeof(line));
    if (ret == 0) {
      // 检测到客户端关闭
      printf("client closed!\n");
      disconnect(cfd, epfd);
    } else if (ret == -1) {
      if (errno == EAGAIN || errno == EINTR)
        continue;
      else {
        perror("recv error");
        exit(1);
      }
    } else {
      // 对首行字符串拆分
      char method[24], path[256], protocol[16];
      sscanf(line, "%[^ ] %[^ ] %[^ ]", method, path, protocol);
      // printf("%s %s %s\n", method, path, protocol);
      while (1) { // 把无用的数据从缓冲区中读走
        char buf[1024] = {0};
        ret = get_line(cfd, buf, sizeof(buf));
        if (ret == 1 || ret == -1) {
          break;
        }
        // printf("%s\n", buf);
      }
      // sleep(1);
      // 判断是不是GET请求
      if (strncasecmp(method, "GET", 3) == 0) {
        char *file = path + 1; // 取出客户端需要访问的文件名
        if (strcmp(path, "/") == 0)
          file = "./"; // 当前资源目录
        http_request(cfd, file);
      }
    }
  } while (0);
}

// 处理新连接事件
void do_accept(int lfd, int epfd) {
  struct sockaddr_in clientaddr;
  socklen_t clientaddrlen = sizeof(clientaddr); // 这是一个传出参数
  int cfd = accept(lfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
  if (cfd == -1) {
    perror("accept error");
    exit(1);
  }
  // 打印客户端IP和port
  char buf[MAXSIZE] = {0};
  printf("client IP: %s, client port: %d\n",
         inet_ntop(AF_INET, &clientaddr.sin_addr, buf, sizeof(buf)),
         ntohs(clientaddr.sin_port));
  // 设置cfd非阻塞
  int flag = fcntl(cfd, F_GETFL);
  flag |= O_NONBLOCK;
  fcntl(cfd, F_SETFL, flag);

  // 将新节点cfd挂到epoll树上监听
  struct epoll_event ev;
  ev.data.fd = cfd;

  // 边沿触发模式  ET
  ev.events = EPOLLIN | EPOLLET;

  int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
  if (ret == -1) {
    perror("epoll_ctl add cfd error");
    exit(1);
  }
}

// 创建套接字lfd并挂上树，同时返回该文件描述符
int init_listen_fd(int port, int epfd) {
  int lfd;
  int ret;
  // 套接字结构体
  struct sockaddr_in servaddr;

  // 创建套接字
  lfd = socket(AF_INET, SOCK_STREAM, 0);
  if (lfd == -1) {
    perror("socket error");
    exit(1);
  }
  // 初始化servaddr结构体
  bzero(&servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(SERV_PORT);
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  // 端口复用
  int opt = 1;
  setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  // 绑定端口
  ret = bind(lfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
  if (ret == -1) {
    perror("bind error");
    exit(1);
  }
  // 最大同时连接数
  ret = listen(lfd, 128);
  // lfd添加到 epoll树上

  struct epoll_event tep;
  tep.events = EPOLLIN;
  tep.data.fd = lfd;
  // 指定监听为读
  ret = epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &tep); // 把lfd挂到红黑树上
  if (ret == -1) {
    perror("epoll_ctl add lfd error");
    exit(1);
  }
  return lfd;
}

// 运行epoll
void epoll_run(int port) {

  int i = 0;
  struct epoll_event all_events[MAXSIZE];
  // 创建一个epoll对象
  int epfd = epoll_create(MAXSIZE);
  if (epfd == -1) {
    perror("epoll_create error");
    exit(1);
  }
  // 创建获得套接字文件描述符lfd, 并添加至监听树
  int lfd = init_listen_fd(port, epfd);
  // 监听节点对应的事件
  while (1) {

    int ret = epoll_wait(epfd, all_events, MAXSIZE,
                         -1); // 没有读到则一直阻塞 否则返回满足事件的个数
    if (ret == -1) {
      perror("epoll_wait error");
      exit(1);
    }
    struct epoll_event *pev; // 临时指针
    for (i = 0; i < ret; i++) {
      pev = &all_events[i];
      if (!(pev->events & EPOLLIN)) // 如果不是读事件 就继续找
        continue;
      if (pev->data.fd == lfd) {
        do_accept(lfd, epfd); // 处理新连接请求
      } else {
        do_read(pev->data.fd, epfd); // 处理读入数据
      }
    }
  }
}

int main(int argc, char *argv[]) {
  // 命令行参数获取 端口和server提供的目录
  if (argc < 3) {
    printf("./server port web_index_file_path\n");
    exit(1);
  }
  // 把字符串型的端口转换为整型
  int port = atoi(argv[1]);
  // 改变进程工作目录
  int ret = chdir(argv[2]);
  if (ret != 0) {
    perror("chdir error");
    exit(1);
  }
  // 启动epoll监听
  epoll_run(port);
  return 0;
}