#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

int main() {
    std::vector<int> arr;
    std::mutex mtx;
    std::thread t2([&] {
        for (int i = 0; i < 1000; i++) {
            // 这是在这里打了个标记，并没有加锁
            std::unique_lock grd(mtx, std::defer_lock);
            printf("before the lock\n");
            grd.lock();
            arr.push_back(2);
            grd.unlock();
            printf("outside of lock\n");
        }
    });
    t2.join();
    return 0;
}
