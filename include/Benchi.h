//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_BENCHI_H
#define SERVER_BENCHI_H
#include "Car.h"
class Benchi: public Car{
public:
    std::string get_name()override;
};
#endif //SERVER_BENCHI_H
