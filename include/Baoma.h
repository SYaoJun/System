//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_BAOMA_H
#define SERVER_BAOMA_H
#include "Car.h"

class Baoma: public Car{
public:
    std::string get_name() override;
};
#endif //SERVER_BAOMA_H
