#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  char buf[1024];
  scanf("%s", buf);
  printf("stdin = %s", buf);
  return 0;
}