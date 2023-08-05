
#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Person{
    public:
        int age;
        string name;
};

// 定义哈希函数
size_t hash_func(const Person &p) {
  size_t h1 = hash<int>()(p.age);
  size_t h2 = hash<string>()(p.name);
  return h1 ^ (h2 << 1);
}

// 定义相等函数
bool equal_func(const Person &p1, const Person &p2) {
  return p1.age == p2.age && p1.name == p2.name;
}

// 创建自定义类的unordered_map
int main() {
  unordered_map<Person, int, decltype(&hash_func), decltype(&equal_func)> myMap(10, hash_func, equal_func);

  Person p1 = { 20, "Tom"};
  Person p2 = { 25, "Jarry"};
  Person p3 = { 20, "Rose"};

  myMap[p1] = 100;
  myMap[p2] = 200;
  myMap[p3] = 300;

  cout << myMap[p1] << endl;
  cout << myMap[p2] << endl;
  cout << myMap[p3] << endl;

  return 0;
}
