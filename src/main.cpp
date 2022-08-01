#include <iostream>
#include "Student.h"
#include "Singleton.h"
#include "Benchi.h"
#include "BenchiFactory.h"
#include "BaomaFactory.h"
#include <vector>

using namespace std;
int main() {
//    auto *student = new Student(18, "yaojun");
//    // 如果没接受返回值，会warning
////    student->get_age();
//    std::cout<<student->get_age()<<std::endl;
    // 单例模式

//    auto a = Singleton::getSingleton();
//    auto b = Singleton::getSingleton();
//    std::cout<<a<<std::endl;
//    std::cout<<b<<std::endl;





    // 原来创建兑现
//    Car *c = new Benchi();
//    std::cout<<c->get_name()<<std::endl;


//    // 工厂模式创建对象
//    Car *d = (new BenchiFactory())->getCar();
//    std::cout<<d->get_name()<<std::endl;


    // 用宝马车
//    Car *x = (new BaomaFactory)->getCar();
//    std::cout<<x->get_name()<<std::endl;
    vector<int> t{1,2,3,2,2,9};
    int res = -1;
    for(auto x: t){
        if(res == -1) res = x;
         // 10
         // 01
         // 11
         // 11
         // 11
         // 101
        else res &= x;
    }
    cout<<res<<endl;
    return 0;
}
