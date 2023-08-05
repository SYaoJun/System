#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
std::vector<int> buffer;
const int maxSize = 10;

void producer() {
    for (int i = 1; i <= 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx); // 使用 std::unique_lock 加锁
        cv.wait(lock, [] { return buffer.size() < maxSize; }); // 等待条件满足（缓冲区未满）
        buffer.push_back(i);
        std::cout << "Produced: " << i << std::endl;
        cv.notify_all(); // 通知等待的消费者
    }
}

void consumer() {
    for (int i = 1; i <= 20; ++i) {
        std::unique_lock<std::mutex> lock(mtx); // 使用 std::unique_lock 加锁
        cv.wait(lock, [] { return !buffer.empty(); }); // 等待条件满足（缓冲区非空）
        int data = buffer.back();
        buffer.pop_back();
        std::cout << "Consumed: " << data << std::endl;
        cv.notify_all(); // 通知等待的生产者
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);
    producerThread.join();
    consumerThread.join();
    return 0;
}
