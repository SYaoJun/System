//
// Created by 姚军 on 2022/8/13.
//

#include <iostream>
#include <chrono>
typedef long long LL;
int main(){
    // 线性计算:1 到1e5
    auto start = std::chrono::steady_clock::now();
    LL new_total = 0;
    for(int i = 0; i < 100000; i++) {
        new_total += i*(LL)i;
    }
    printf("linear scan result = %lld\n", new_total);
    auto end = std::chrono::steady_clock::now();
    auto duration_ms = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    printf( "线性扫描花费了%lld毫秒\n", duration_ms);
    return 0;
}