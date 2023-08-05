#include <iostream>
#include <thread>

using namespace std;

void output(int i) {
	cout << i << endl;
}

int main() {
	for (uint8_t i = 0; i < 4; i++) {
		thread t(output, i);
		t.detach();	
	}
		
	getchar();
	return 0;
}