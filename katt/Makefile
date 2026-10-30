CC = gcc
CFLAGS = -std=c23 -Wall -Wextra -Wpedantic -Wconversion -g -fsanitize=address,undefined

katt: katt.c ../lib/io.c ../lib/io.h
	$(CC) $(CFLAGS) -o $@ katt.c ../lib/io.c

run: katt
	./katt $@

test: katt
	./katt Makefile

clean:
	rm -f katt

.PHONY: run clean test build
