//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_CAR_H
#define SERVER_CAR_H
#include <string>
class Car{
public:
    virtual std::string get_name() = 0;
    Car()=default;
};
#endif //SERVER_CAR_H
