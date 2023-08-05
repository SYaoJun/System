all: hello world
compute: compute.cpp
	g++ compute.cpp -o compute -std=c++17
multi-thread: multi-thread.cpp
	g++ multi-thread.cpp -o multi-thread -std=c++17
multi-process: multi-process.cpp
	g++ multi-process.cpp -o multi-process -std=c++17
chrono_test: chrono_test.cpp
	g++ chrono_test.cpp -o chrono_test -std=c++17
fork_test: fork_test.cpp
	g++ fork_test.cpp -o fork_test -std=c++17
hello: hello.cpp
	g++ hello.cpp -o xxx
world: world_test.go
	go test -v world_test.go

thread_v1: thread_v1.cpp
	g++ thread_v1.cpp -o thread_v1 -std=c++17
mutex: mutex.cpp
	g++ mutex.cpp -o mutex -std=c++17
condition_variable: condition_variable.cpp
	g++ condition_variable.cpp -o condition_variable -std=c++17
unique_lock: unique_lock.cpp
	g++ unique_lock.cpp -o unique_lock -std=c++17

future: future.cpp
	g++ future.cpp -o future -std=c++17
promise: promise.cpp
	g++ promise.cpp -o promise -std=c++17
clean:
	rm *.o main 
