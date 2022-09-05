//
// Created by 姚军 on 2022/9/5.
//
#include "db.h"
#include "entry.h"
#include <fcntl.h>

ErrorInfo miniDB::delete_(std::string) {
    return ErrorInfo();
}

STATUS miniDB::put(std::string key, std::string value) {
    // 1. 打开文件
    int fd = open(absFilePath.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        printf("open failed!");
        return STATUS::FAILED;
    }else{
        printf("open success!");
    }
    this->dbFile->fd = fd;
    // 2. 写入磁盘
    this->mutex_.lock();
    Entry entry(key, value, MARK::PUT);
    this->dbFile->write_(entry);
    // 3. 更新索引
    this->dbFile->loadIndex();
    this->mutex_.unlock();
    return STATUS::SUCCESS;;
}

std::pair<std::string, ErrorInfo> miniDB::get(std::string) {

    return std::pair<std::string, ErrorInfo>();
}

STATUS miniDB::merge() {

}
