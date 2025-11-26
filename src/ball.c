#include "ball.h"
#include "config.h"
#include "monster.h"
#include "raylib.h"

Ball balls[100];
int numballs = 0;

void ThrowBall(Vector2 position, Vector2 velocity, Color color) {
    if (numballs < 100) {
        balls[numballs].position = position;
        balls[numballs].velocity.x = velocity.x * 4;
        balls[numballs].velocity.y = velocity.y * 4;
        balls[numballs].color = color;
        balls[numballs].isActive = true;
        numballs++;
    }
}

void UpdateBalls(void) {
    for (int i = 0; i < numballs; i++) {
        balls[i].position.x += balls[i].velocity.x;
        balls[i].position.y += balls[i].velocity.y;

        if (balls[i].position.y < 0 || balls[i].position.y > screenHeight) {
            balls[i].isActive = false;
        }
    }
}

void CheckBallMonsterCollisions(void) {
    for (int i = 0; i < numballs; i++) {
        for (int j = 0; j < monsterCount; j++) {
            if (CheckCollisionCircleRec(balls[i].position, 5, Monsters[j].rect)) {
                Monsters[j].rect.y = -50;
                Monsters[j].rect.x = GetRandomValue(0, screenWidth - 50);
                balls[i].isActive = false;
            }
        }
    }
}

