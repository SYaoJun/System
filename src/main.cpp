#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
#include <gtest/gtest.h>

int add(int a,int b){
    return a+b;
}
TEST(testCase,test0){
    EXPECT_EQ(add(2,3),5);
}
int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
