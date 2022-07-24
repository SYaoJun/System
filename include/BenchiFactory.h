//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_BENCHIFACTORY_H
#define SERVER_BENCHIFACTORY_H
#include "CarFactory.h"
class BenchiFactory: public CarFactory{
public:
    Car * getCar() override;
};
#endif //SERVER_BENCHIFACTORY_H
