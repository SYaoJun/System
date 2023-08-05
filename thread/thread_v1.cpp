#include <iostream>
#include <thread>

void output(int i) {
	std::cout << i << std::endl;
}

int main() {
	int x = 100;
	std::thread t1(output, x);
    std::thread::id t1_id = t1.get_id();
	t1.join();
	return 0;
}