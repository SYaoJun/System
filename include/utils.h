//
// Created by 姚军 on 2022/9/5.
//

#ifndef SERVER_UTILS_H
#define SERVER_UTILS_H
#include <string>
const std::string relativeFilePath = "../file/minidb/minidb.data";
const std::string absFilePath = "/tmp/minidb/test.data";
const int HEADER_SIZE = 10;
enum class MARK{
    PUT = 1,
    DEL = 2
};
enum class STATUS{
    SUCCESS = 1,
    FAILED = 2,
    UNKNOWN = 3
};
using ErrorInfo = std::string;
#endif //SERVER_UTILS_H
