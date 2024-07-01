#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 0
#define MAX_CONN 20
int main(int argc, char* argv[]) {
    // 1. 创建一个socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        perror("create socket");
        exit(EXIT_FAILURE);
    }
    // 2. 端口复用
    int reuse = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    // 如果port=0，则表示使用临时端口，系统随机分配没有被占用的端口
    serverAddr.sin_port = htons(SERV_PORT);
    // 监听任意IP
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    // 3. 绑定IP
    if (bind(lfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) == -1) {
        exit(EXIT_FAILURE);
    }
    // 4. 设置监听上限
    if (listen(lfd, MAX_CONN) == -1) {
        exit(1);
    }
    int temporary_port = SERV_PORT;
    if (!temporary_port) {
        struct sockaddr_in ad;
        memset(&ad, 0, sizeof(struct sockaddr_in));
        socklen_t len = sizeof(struct sockaddr_in);
        // 5. 获取临时端口PORT
        if (getsockname(lfd, (struct sockaddr *)&ad, &len) == -1) {
            exit(EXIT_FAILURE);
        } else {
            temporary_port = ntohs(ad.sin_port);
        }
    } 
    printf("port = %d\n", temporary_port);
    return 0;
}