//
// Created by 姚军 on 2022/7/24.
//

#ifndef SERVER_ADD_H
#define SERVER_ADD_H
#include <string>
#include <utility>
class Student{
public:
    int age;
    std::string name;
    Student(int age_, std::string name_): age(age_), name(std::move(name_)){}
    // nodiscard如果没有接受者，编译器会报warning
     [[nodiscard]] int get_age() const;
    ~Student();
};
#endif //SERVER_ADD_H
