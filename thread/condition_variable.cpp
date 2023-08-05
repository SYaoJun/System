#include <iostream>           
#include <thread>            
#include <mutex>             
#include <condition_variable> 
#include <vector>
#include <chrono>
std::mutex mtx;
std::condition_variable cv;
bool ready = false;
 
void print_id (int id) {
    std::unique_lock<std::mutex> lck(mtx);
    cv.wait_for(lck, std::chrono::seconds(1), []{return ready;});
    std::cout << "thread " << id << '\n';
}
 
void go() {
    //修改ready标记，并通知打印线程工作
    std::unique_lock<std::mutex> lck(mtx);
    ready = true;
    cv.notify_all();
}
 
int main (){
    std::vector<std::thread> threads(10);
    // 创建10个线程，每个线程当ready标记为真时打印自己的id号
    for (int i=0; i<10; ++i)
        threads[i] = std::thread(print_id,i);
 
    std::cout << "10 threads ready to race...\n";
    go();                    
    for (auto& th : threads) th.join();
 
    return 0;
}
