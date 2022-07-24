//
// Created by 姚军 on 2022/7/24.
//
#include "Singleton.h"

// static 要特殊处理
Singleton* Singleton::instance = new Singleton();
Singleton* Singleton::getSingleton() {
    return instance;
}

Singleton::Singleton() {

}

