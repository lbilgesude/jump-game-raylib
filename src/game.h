#ifndef GAME_H
#define GAME_H

#include "raylib.h"

extern Camera2D camera;
extern int score;
extern int highScore;

void StartGame(void);
void UpdateGame(void);
void DrawGame(void);
void UpdateCamera(void);

#endif // GAME_H

