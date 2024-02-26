#include <arpa/inet.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6670

void start_auctioneer(int port, int maxConnections) {
    int lfd;
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd == -1) {
        exit(1);
    }
    int reuse = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    if (bind(lfd, (struct sockaddr *)&serverAddr, sizeof(struct sockaddr)) ==
        -1) {
        exit(1);
    }
    if (listen(lfd, maxConnections) == -1) {
        exit(1);
    }
    int serverPort;
    if (port == 0) {
        struct sockaddr_in ad;
        memset(&ad, 0, sizeof(struct sockaddr_in));
        socklen_t len = sizeof(struct sockaddr_in);
        if (getsockname(lfd, (struct sockaddr *)&ad, &len) == -1) {
            exit(1);
        } else {
            serverPort = ntohs(ad.sin_port);
        }
    } else {
        serverPort = port;
    }
    fprintf(stderr, "port = %d\n", serverPort);
    fflush(stderr);
}
int main() {
    int port = 0;
    int maxConnections = 100;
    start_auctioneer(port, maxConnections);
    return 0;
}