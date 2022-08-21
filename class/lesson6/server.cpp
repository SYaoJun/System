#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6670

int main(void){
    int lfd, cfd;
    char buf[BUFSIZ], client_IP[BUFSIZ]; //4k或者8k
    struct sockaddr_in serv_addr, clie_addr;
    // socket是一个input和output缓冲区
    lfd = socket(AF_INET, SOCK_STREAM, 0); //创建套接字

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr); //点分十进制转网络字节序

    // 绑定端口 类似于将上课的教室定下来，而客户端就是学生，学生需要知道教室
    bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr) );
    // 监听端口
    listen(lfd, 128); //最大同时连接数
    socklen_t clie_addr_len; //套接字长度
    clie_addr_len = sizeof(clie_addr);
    // 接收请求
    cfd = accept(lfd, (struct sockaddr*)&clie_addr, &clie_addr_len );
    printf("client IP: %s, client port: %d\n",
           inet_ntop(AF_INET, &clie_addr.sin_addr.s_addr, client_IP, sizeof(client_IP)),
           ntohs(clie_addr.sin_port));
    int i, n;
    // 终端输入nc 127.0.0.1 6670 去发送数据
    // 服务端如何支持rest ful风格的请求get post put delete
    while(1){  //一直读 一直写
        n = read(cfd, buf, sizeof(buf));
        for(i = 0; i < n; i++){
            buf[i] = toupper(buf[i]);
        }
        write(cfd, buf, n);
    }
    close(lfd);
    close(cfd);
    return 0;
}