#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include "game.h"

void printScreen();

int main() {
	int exit = 0;

	initscr();
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
	curs_set(0); //hide cursor

	while (!exit) {
		switch (getch()) {
			case 'q':
				exit = 1;
				break;
			case KEY_UP:
				movePlayer(-1);
				break;
			case KEY_DOWN:
				movePlayer(1);	
				break;
		}
		updateBall();
		updateBot();
		printScreen();

		if (gameover) {
			move(SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2 - 4);
			printw("GAMEOVER");
			refresh();
			sleep(3);
			exit = 1;
		}

		refresh();
		flushinp();
		usleep(500000);
		clear();
	}
	endwin();
	return 0;
}

void printScreen() {
	//border at top
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		printw("-");
	}
		
	move(ball.y, ball.x);
	printw("O");
	move(player.y, player.x);
	printw("|");
	move(bot.y, bot.x);
	printw("|");

	//border at bottom
	move(SCREEN_HEIGHT,0);
	for (int i = 0; i < SCREEN_WIDTH; i++) {
		printw("-");
	}
}
