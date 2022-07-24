//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_BAOMAFACTORY_H
#define SERVER_BAOMAFACTORY_H
#include "CarFactory.h"
class BaomaFactory: public CarFactory{
public:
    Car * getCar() override;
};
#endif //SERVER_BAOMAFACTORY_H
