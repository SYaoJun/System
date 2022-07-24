//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_SINGLETON_H
#define SERVER_SINGLETON_H
class Singleton{
private:
    Singleton();
    static Singleton* instance;
public:
    static Singleton* getSingleton();
};
#endif //SERVER_SINGLETON_H
