CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic -Werror -O2

.PHONY: all run clean

all: register_demo

register_demo: main.c
	$(CC) $(CFLAGS) main.c -o register_demo

run: register_demo
	./register_demo

clean:
	rm -f register_demo
