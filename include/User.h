//
// Created by 姚军 on 2022/8/6.
//

#ifndef SERVER_USER_H
#define SERVER_USER_H

#include <string>
class User{
public:
    virtual std::string getName()=0;
    virtual int getAge()=0;
};
#endif //SERVER_USER_H
