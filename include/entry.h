//
// Created by 姚军 on 2022/9/5.
//

#ifndef SERVER_ENTRY_H
#define SERVER_ENTRY_H
#include <string>
#include <memory>
#include "utils.h"

class Entry{
public:
    std::string key;
    std::string value;
    int keySize;
    int valueSize;
    MARK mark;
    Entry() = default;
    Entry(std::string&, std::string&, MARK);
    std::pair<Entry, ErrorInfo> decode(std::string buf);
    std::pair<std::string, ErrorInfo> encode();
    int getSize();
};
#endif //SERVER_ENTRY_H
