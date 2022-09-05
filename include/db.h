//
// Created by 姚军 on 2022/9/5.
//

#ifndef SERVER_DB_H
#define SERVER_DB_H
#include <unordered_map>
#include <string>
#include <shared_mutex>
#include <memory>
#include <utility>
#include "utils.h"
#include "db_file.h"
class miniDB{
public:
    // 内存中的索引
    std::unordered_map<std::string, std::string> indexes;
    // 数据文件
    DBFile *dbFile;
    // 数据目录
    std::string dirPath;
    std::shared_mutex mutex_;

    std::pair<std::string, ErrorInfo> get(std::string);
    STATUS put(std::string, std::string);
    ErrorInfo delete_(std::string);
    STATUS merge();
};
#endif //SERVER_DB_H
