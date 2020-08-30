CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic 
INCLUDE=-lncurses

all: cpong.c game.h game.o
	$(CC) cpong.c game.o $(CFLAGS) $(INCLUDE) -o cpong

clean:
	rm cpong game.o
