#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/mman.h>
int main(){
    
    int fd = open("mytest.txt", O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("open error!");
        exit(1);
    }
    //申请共享映射
    void *p = mmap(NULL, 6, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (p == MAP_FAILED)
    {
        perror("mmap error!");
        exit(1);
    }
    strcpy((char *)p+4, "efg");
    int ret = munmap(p, 8); //释放共享映射
    if (ret == -1)
    {
        perror("munmap error!");
        exit(1);
    }
    close(fd);
    return 0;
}
