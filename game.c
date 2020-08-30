#include "game.h"

const int SCREEN_WIDTH = 30;
const int SCREEN_HEIGHT = 10;
int gameover = 0;
Ball ball = {SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, -1, -1};
Paddle player = {0, SCREEN_HEIGHT / 2};
Paddle bot = {SCREEN_WIDTH - 1, SCREEN_HEIGHT / 2};

void movePlayer(int y) {
	if (((y == -1) && (player.y != 1)) ||
		((y == 1) && player.y != (SCREEN_HEIGHT - 1))) {
		player.y += y;
	}
}

void updateBot() {
	bot.y = ball.y;
}

void updateBall() {
	if ((ball.vx < 0) && (ball.x == 1) && (player.y != ball.y)) {
		gameover = 1;
		ball.x += ball.vx;
		ball.y += ball.vy;
		return;
	}
	

	if ((ball.x == 1) || (ball.x == bot.x - 1)) {
		ball.vx = -ball.vx;
	}

	if ((ball.y == 1) || (ball.y == SCREEN_HEIGHT - 1)) {
		ball.vy = -ball.vy;
	}
	
	ball.x += ball.vx;
	ball.y += ball.vy;
}

