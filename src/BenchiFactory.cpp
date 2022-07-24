//
// Created by 姚军 on 2022/7/24.
//
#include "BenchiFactory.h"
#include "Benchi.h"

Car *BenchiFactory::getCar() {
    return new Benchi();
}

