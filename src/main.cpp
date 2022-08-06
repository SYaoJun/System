#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <unistd.h>
#include <fcntl.h>
using namespace std;
#include <gtest/gtest.h>
#include "Solution.h"
#include "MockUser.h"
int main(int argc,char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
TEST(testCase2,testSolution){
    Solution obj;
    int res = obj.add(1, 2);
    EXPECT_EQ(res, 3);
}

TEST(testCase3, testMockUser){
    cout << "func begin: " << __func__ << endl;
    MockUser james;
    EXPECT_CALL(james, getAge())
            .Times(::testing::AtLeast(3))
            .WillOnce(::testing::Return(18))
            .WillOnce(::testing::Return(27))
            .WillRepeatedly(::testing::Return(19));
    cout << "1. " << james.getAge() << endl;
    cout << "2. " << james.getAge() << endl;
    cout << "3. " << james.getAge() << endl;
    cout << "4. " << james.getAge() << endl;
    cout << "5. " << james.getAge() << endl;
    cout << "func end:" << __func__ << endl;
}

TEST(testCase4, testMockUser2){
    cout << "func begin: " << __func__ << endl;
    MockUser james;
    EXPECT_CALL(james, getName())
            .Times(::testing::AtLeast(3))
            .WillOnce(::testing::Return("hello"))
            .WillRepeatedly(::testing::Return("world"));
    cout << "1. " << james.getName() << endl;
    cout << "2. " << james.getName() << endl;
    cout << "3. " << james.getName() << endl;
    cout << "4. " << james.getName() << endl;
    cout << "5. " << james.getName() << endl;
    cout << "func end:" << __func__ << endl;
}
