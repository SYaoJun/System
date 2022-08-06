//
// Created by 姚军 on 2022/8/6.
//

#ifndef SERVER_MOCKUSER_H
#define SERVER_MOCKUSER_H
#include "User.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
class MockUser: public User{
public:
    MOCK_METHOD(std::string, getName, (), (override));
    MOCK_METHOD(int, getAge, (), (override));
};
#endif //SERVER_MOCKUSER_H
