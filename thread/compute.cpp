#include <iostream>
#include <cmath>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <unistd.h>
#include <iomanip>

static const int MAX = 1e8;
using LL = long long;
static LL sum = 0;
void worker(int minV, int maxV){
    for(int i = minV; i <= maxV; i++){
        sum +=  i*(LL)i;
    }
}
void serial_task(){
    // 单线程 计算1e8的平方根之和
    auto start_time = std::chrono::steady_clock::now();
    sum = 0;
    worker(1, MAX);
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout<<"Serial task finish, "<< ms <<" ms consumed, Result: " << std::fixed << std::setprecision(3)<<sum << std::endl;
    printf("线性：%lld\n", sum);
}
static std::mutex mtx;
void concurrent_worker(int minV, int maxV){
    LL tmp_sum = 0;
    for(int i = minV; i <= maxV; i++){
        tmp_sum +=  i*(LL)i;

    }
    mtx.lock();
    sum += tmp_sum;
    mtx.unlock();
}
void concurrent_task(int minV, int maxV){
    auto start_time = std::chrono::steady_clock::now();
    unsigned concurrent_count = std::thread::hardware_concurrency(); // 获取当前硬件支持多少个线程并发执行
//    std::cout<< " hardware_concurrency: "<< concurrent_count<< std::endl;
    std::vector<std::thread> threads;
    minV = 0;
    sum = 0;
    for(int t = 0; t < concurrent_count; t++){
        int range = maxV / concurrent_count *(t + 1);
        threads.push_back(std::thread(concurrent_worker, minV, range));
        minV = range + 1;
    }
    for(auto &t: threads){
        t.join();
    }
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
     std::cout<<"concurrency task finish, "<< ms <<" ms consumed, Result: " << std::fixed << std::setprecision(3)<<sum << std::endl;
    printf("并发：%lld\n", sum);
}

int main(){
    // 线性
    serial_task();
    // 多线程
    concurrent_task(1, MAX);
    return 0;
}
