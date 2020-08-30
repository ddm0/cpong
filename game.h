#ifndef GAME_H
#define GAME_H

typedef struct Ball {
	int x;
	int y;
	int vx;
	int vy;
} Ball;

typedef struct Paddle {
	const int x;
	int y;
} Paddle;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

extern int gameover;
extern Ball ball;
extern Paddle player;
extern Paddle bot;

//takes -1 or 1
void movePlayer(int y);
void updateBot();
void updateBall();

#endif
