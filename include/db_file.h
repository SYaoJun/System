//
// Created by 姚军 on 2022/9/5.
//

#ifndef SERVER_DB_FILE_H
#define SERVER_DB_FILE_H
#include <memory>
#include <utility>
#include "entry.h"

class DBFile{
public:
    int fd;
    int offset;
    void read(Entry);
    void write_(Entry);
    void loadIndex();
};

#endif //SERVER_DB_FILE_H
