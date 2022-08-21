//
// Created by 姚军 on 2022/8/13.
//
#include <stdio.h>
#include <unistd.h>
#include <iostream>

int main(){
    std::cout<<"主进程 pid = "<<getpid()<<std::endl;
    auto pid = fork();
    if(pid == 0) {
        // 子进程
        std::cout<<"子进程getpid() pid = "<<getpid()<<std::endl;

    }else if(pid == -1){
        std::cout<<"创建子进程失败"<<std::endl;
    }else{
        // 父进程
        std::cout<<"子进程 pid = "<<pid<<std::endl;
    }
    return 0;
}
