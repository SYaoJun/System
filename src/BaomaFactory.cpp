//
// Created by 姚军 on 2022/7/24.
//
#include "BaomaFactory.h"
#include "Baoma.h"
Car *BaomaFactory::getCar() {
    return new Baoma();
}

