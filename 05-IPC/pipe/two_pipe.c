#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define PIPE_READ_AND_WRITE 2
#define PIPE_READ 0
#define PIPE_WRITE 1
#define THREAD_NUM 3
void A(int pipeAB[PIPE_READ_AND_WRITE], int pipeAC[PIPE_READ_AND_WRITE]) {
    close(pipeAB[PIPE_READ]);
    close(pipeAC[PIPE_READ]);
    dup2(pipeAB[PIPE_WRITE], STDOUT_FILENO);
    dup2(pipeAC[PIPE_WRITE], STDERR_FILENO);

    perror("gggggggggggggg\n");
    execlp("date", "date", NULL);
}

void B(int pipeAB[PIPE_READ_AND_WRITE], int pipeAC[PIPE_READ_AND_WRITE]) {
    close(pipeAB[PIPE_WRITE]);
    close(pipeAC[PIPE_READ]);
    close(pipeAC[PIPE_WRITE]);
    dup2(pipeAB[PIPE_READ], STDIN_FILENO);
    close(pipeAB[PIPE_READ]);

    char buf[1024];
    read(STDIN_FILENO, buf, 1024);
    printf("stdout = %s", buf);

    exit(0);
}
void C(int pipeAB[PIPE_READ_AND_WRITE], int pipeAC[PIPE_READ_AND_WRITE]) {
    close(pipeAB[PIPE_READ]);
    close(pipeAB[PIPE_WRITE]);
    close(pipeAC[PIPE_WRITE]);
    dup2(pipeAC[PIPE_READ], STDIN_FILENO);
    close(pipeAC[PIPE_READ]);
    char buf[1024];
    read(STDIN_FILENO, buf, 1024);
    printf("stderr = %s", buf);
    exit(0);
}
int main() {
    int pipeAB[PIPE_READ_AND_WRITE];
    int pipeAC[PIPE_READ_AND_WRITE];
    int children[THREAD_NUM];
    pipe(pipeAB);
    pipe(pipeAC);
    pid_t pid;

    for (int i = 0; i < THREAD_NUM; i++) {
        pid = fork();
        if (pid == 0) {
            if (i == 0) {
                A(pipeAB, pipeAC);
            } else if (i == 1) {
                B(pipeAB, pipeAC);
            } else {
                C(pipeAB, pipeAC);
            }
        } else {
            children[i] = pid;
        }
    }

    int status;
    for (int i = 0; i < THREAD_NUM; i++) {
        waitpid(children[i], &status, 0);
    }
    return 0;
}