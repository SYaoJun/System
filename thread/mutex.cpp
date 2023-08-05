#include <iostream>
#include <thread>
#include <mutex>
int sum = 0;
std::mutex m;
void worker() {
    for(int i = 0; i < 100000; i++) {
        m.lock();
        sum += 1;
        m.unlock();
    }
}
int main() {

    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();
    std::cout<<sum<<std::endl;
    return 0;
}