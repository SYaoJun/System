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

clean:
	rm *.o main 
