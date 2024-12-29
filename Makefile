main: main.c
	gcc main.c -o main -Wall -Wextra -pedantic -std=c99 -g
.PHONY: clean
clean:
	rm -f main