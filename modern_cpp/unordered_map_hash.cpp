#include <iostream>
#include <unordered_map>
#include <stdio.h>
#include <stdlib.h>

class mypair
{
public:
    char first;
    char second;

    mypair(const char& a, const char& b)
    {
        first = a;
        second = b;
    }

    bool operator==(const mypair& rhs) const{
        return rhs.first == first && rhs.second == second;
    }

};

struct hashname
{
    size_t operator()(const mypair& tmp) const
    {
        return (std::hash<char>()(tmp.first)) ^ (std::hash<char>()(tmp.second));
    }
};

int main()
{
    std::unordered_map<mypair, int, hashname> mp(20);
    mypair m1('a', 'b');
    mypair m2('a', 'f');
    mp[m1] = 2030;
    mp[m2] = 2023;

    for(auto [key, value] : mp) {
        std::cout<<key.first <<" "<< key.second <<" "<<value<<std::endl;
    }

}