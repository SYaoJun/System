//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_CARFACTORY_H
#define SERVER_CARFACTORY_H
#include "Car.h"
class CarFactory{
public:
    virtual Car* getCar() = 0;

};
#endif //SERVER_CARFACTORY_H
