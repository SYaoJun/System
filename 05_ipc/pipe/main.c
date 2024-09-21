#include <stdio.h>
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
// A.c
#include <stdio.h>

int main() {
    char buffer[128];
    printf("Waiting for input...\n");
    while (fgets(buffer, sizeof(buffer), stdin)) {
        printf("Received: %s", buffer);
    }
    printf("EOF detected. Exiting...\n");
    return 0;
}

