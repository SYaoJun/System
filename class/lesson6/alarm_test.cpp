#include <unistd.h>
#include <stdio.h>
int main(){
    alarm(1); //计时1s 到时后内核发送一个sigalarm信号终止进程, 只能定时秒级
    for(int i = 0;;i++) printf("processing...%d\n", i);
    return 0;
}