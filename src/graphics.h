#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

extern Texture2D playerTexture;
extern Texture2D platformTexture;
extern Texture2D trampolineTexture;
extern Texture2D monsterTexture;
extern Texture2D backgroundTexture;
extern Texture2D endgamebackgroundTexture;

void AddGraph(void);
void UnAddGraph(void);
void MakeOval(Rectangle rec, Color color);

#endif // GRAPHICS_H


