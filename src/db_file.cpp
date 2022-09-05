//
// Created by 姚军 on 2022/9/5.
//
#include "db_file.h"
#include <unistd.h>
#include <iostream>

void DBFile::write_(Entry entry) {
    std::string tmp = entry.key + entry.value;
    int input_size = entry.getSize();
    int write_size = pwrite(this->fd, tmp.c_str(), input_size, this->offset);
    if (write_size == -1){
        perror("write error");
        exit(1);
    }
    printf("write bytes: %d\n", write_size);
    this->offset += write_size;
    std::cout<<"offset = "<<this->offset<<std::endl;
}

void DBFile::read(Entry) {

}

void DBFile::loadIndex() {

}
