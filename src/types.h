#ifndef TYPES_H
#define TYPES_H

#include "raylib.h"
#include "config.h"

typedef struct Player {
    Rectangle rect;
    Vector2 velocity;
    Color color;
    bool isJumping;
    bool isAlive;
    bool platformJumped;
} Player;

typedef struct Platform {
    Rectangle rect;
    Color color;
    bool isActive;
    bool firstJump;
} Platform;

typedef struct Trampoline {
    Rectangle rect;
    Color color;
    bool isActive;
    bool firstJump;
} Trampoline;

typedef struct Monster {
    Rectangle rect;
    Color color;
} Monster;

typedef struct Ball {
    Vector2 position;
    Vector2 velocity;
    Color color;
    float speed;
    bool isActive;
} Ball;

#endif // TYPES_H


