.PHONY: all clean install
all: server ephemeral_port
CC = gcc
CFLAGS += -Wall -Wextra -pedantic -std=gnu99 -g 
########################################################################

nosan: all

asan: CFLAGS += -fsanitize=address,leak,undefined
asan: all

msan: CFLAGS += -fsanitize=memory,undefined -fsanitize-memory-track-origins
msan: all

########################################################################
server: 04_tcp_socket_server.c
	$(CC) $< -o $@ $(CFLAGS)

ephemeral_port: 02_ephemeral_port.c
	$(CC) $< -o $@  $(CFLAGS)

########################################################################
clean:
	rm -rf ephemeral_port server
########################################################################
install:
    @echo "Installing program"