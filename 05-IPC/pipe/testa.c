#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("test a stdout\n");
  perror("teat a stderr\n");
  return 0;
}