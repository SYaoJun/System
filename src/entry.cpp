//
// Created by 姚军 on 2022/9/5.
//
#include "entry.h"
#include <utility>

Entry::Entry(std::string &key, std::string &value, MARK mark) {
    this->key = key;
    this->value = value;
    this->mark = mark;
}

std::pair<std::string, ErrorInfo> Entry::encode() {
    return std::pair<std::string, ErrorInfo>();
}

std::pair<Entry, ErrorInfo> Entry::decode(std::string buf) {
    Entry entry;
    return std::make_pair(entry, ErrorInfo());
}

int Entry::getSize() {
    this->keySize = key.size();
    this->valueSize = value.size();
    return this->keySize + this->valueSize + HEADER_SIZE;
}
