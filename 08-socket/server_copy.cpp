#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6670

int main(void) {
    int lfd, cfd;
    char buf[BUFSIZ], client_IP[BUFSIZ];  // 4k或者8k
    struct sockaddr_in serv_addr, clie_addr;
    // socket是一个input和output缓冲区
    // 文件描述符：37
    lfd = socket(AF_INET, SOCK_STREAM, 0);  // 创建套接字

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);  // 点分十进制转网络字节序

    // 绑定端口 类似于将上课的A5教室定下来，而客户端就是学生，学生需要知道教室A5
    // 绑定提供服务的接口
    bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    // 监听端口
    listen(lfd, 128);         // 最大同时连接数
    socklen_t clie_addr_len;  // 套接字长度
    clie_addr_len = sizeof(clie_addr);
    // 接收请求 阻塞调用 等待
    cfd = accept(lfd, (struct sockaddr *)&clie_addr, &clie_addr_len);
    printf("client IP: %s, client port: %d\n",
           inet_ntop(AF_INET, &clie_addr.sin_addr.s_addr, client_IP, sizeof(client_IP)), ntohs(clie_addr.sin_port));
    int i, n;
    int flag = 0;
    memset(buf, 0, sizeof(buf));
    n = recv(cfd, buf, sizeof(buf), flag);
    if (n == 0) {
        puts("recv error");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        buf[i] = toupper(buf[i]);
    }
    buf[i++] = '!';
    write(STDOUT_FILENO, buf, n + 1);
    close(lfd);
    close(cfd);
    puts("game over!");
    return 0;
}