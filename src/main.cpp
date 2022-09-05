#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "db.h"
#include "utils.h"
#include <unistd.h>
#include <random>

using namespace std;
int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
/**
 * 测试相对路径打开文件
 */
TEST(TestOpenRelativePath, should_return_success_when_open_file){
    // 注意：文件的位置是相对路径，相对于main函数的位置。
    int fd = open(relativeFilePath.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        printf("open failed!");
    }else{
        printf("open success!");
    }
}
/**
 * 测试绝对路径打开文件
 */
TEST(TestAbsoluteFilePath, should_return_success_when_open_file){

    int fd = open(absFilePath.c_str(), O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        printf("open failed!");
    }else{
        printf("open success!");
    }
}
/**
 * 测试put方法
 * 根据key和value写入数据到磁盘
 */
TEST(TestMiniDBPut,TestMiniDBPut){
    miniDB db;
    db.dbFile->offset = 0;
    std::string key = "test_key_";
    std::string value = "test_val_";
    for (int i = 0; i < 10; i ++) {
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        mt19937 rand_num(seed);
        uniform_int_distribution<long long> dist(0, 5);
        int t = dist(rand_num);
        key += to_string(t);
        value += to_string(t);
        std::cout<<"key = "<<key<<" value = "<<value<<std::endl;
        db.put(key, value);
    }
    printf("put success!");
}

TEST(TestMiniDBGet, TestMiniDBGet) {
    miniDB db;
    db.dbFile->offset = 0;
    std::string key = "test";
    for(int i = 0; i < 5; i++) {
        auto val = db.get(key + to_string(i));
        std::cout<<"value = "<< val.first << std::endl;
    }
}
TEST(TestMiniDB_Del, TestMiniDB_Del) {
    miniDB db;
    db.dbFile->offset = 0;
    std::string key = "test_key_78";
    auto res = db.delete_(key);
}
TEST(TestMiniDB_Merge, TestMiniDB_Merge) {
    miniDB db;
    db.dbFile->offset = 0;
    auto res = db.merge();
}