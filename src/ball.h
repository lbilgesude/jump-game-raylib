#ifndef BALL_H
#define BALL_H

#include "types.h"
#include "raylib.h"

extern Ball balls[];
extern int numballs;

void ThrowBall(Vector2 position, Vector2 velocity, Color color);
void UpdateBalls(void);
void CheckBallMonsterCollisions(void);

#endif // BALL_H

