#include "game.h"
#include "config.h"
#include "graphics.h"
#include "audio.h"
#include "player.h"
#include "platform.h"
#include "trampoline.h"
#include "monster.h"
#include "ball.h"
#include "types.h"
#include "raylib.h"

Camera2D camera = { 0 };
int score = 0;
int highScore = 0;

void StartGame(void) {
    extern Player player;
    
    AddGraph();
    AddSounds();
    
    InitPlayer();
    StartPlatforms();
    InitTrampolines();
    InitMonsters();

    camera.target = (Vector2){ player.rect.x + playerWidth / 2, player.rect.y + playerHeight / 2 };
    camera.offset = (Vector2){ screenWidth / 2, screenHeight / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void UpdateCamera(void) {
    extern Player player;
    camera.target.y = player.rect.y + playerHeight / 2;
    camera.offset.y += player.velocity.y * cameraSpeed * GetFrameTime();

    if (camera.offset.y < screenHeight / 2) {
        camera.offset.y = screenHeight / 2;
    }
}

void UpdateGame(void) {
    extern Player player;
    UpdatePlayerMovement();
    UpdateTrampolines();
    UpdatePlayerPhysics();
    CheckPlayerCollisions();
    CheckPlayerBounds();
    UpdateCamera();
    UpdateBalls();
    CheckBallMonsterCollisions();

    if (score > highScore) {
        highScore = score;
    }
}

void DrawGame(void) {
    extern Player player;
    extern Platform platforms[];
    extern Trampoline trampolines[];
    extern Monster Monsters[];
    extern Ball balls[];
    extern int numballs;
    
    BeginDrawing();
    ClearBackground(RAYWHITE);
    
    DrawTexture(backgroundTexture, 0, 0, WHITE);

    BeginMode2D(camera);

    DrawTexture(playerTexture, (int)player.rect.x, (int)player.rect.y, WHITE);

    for (int i = 0; i < platformCount; i++) {
        DrawTexture(platformTexture, (int)platforms[i].rect.x, (int)platforms[i].rect.y, WHITE);
    }

    for (int i = 0; i < platformCount / 2; i++) {
        if (trampolines[i].isActive) {
            DrawTexture(trampolineTexture, (int)trampolines[i].rect.x, (int)trampolines[i].rect.y, WHITE);
        }
    }

    for (int i = 0; i < monsterCount; i++) {
        DrawTexture(monsterTexture, (int)Monsters[i].rect.x, (int)Monsters[i].rect.y, WHITE);
    }

    EndMode2D();

    for (int i = 0; i < numballs; i++) {
        if (balls[i].isActive) {
            DrawCircleV(balls[i].position, 10, balls[i].color);
        }
    }
    
    static bool onePressed = false;
    static bool twoPressed = false;
    static bool threePressed = false;

    if (IsKeyPressed(KEY_ONE) && !onePressed) {
        ThrowBall((Vector2){player.rect.x + player.rect.width / 2, player.rect.y + player.rect.height / 2}, (Vector2){-2, -2}, PURPLE);
        onePressed = true;
    } else if (IsKeyReleased(KEY_ONE)) {
        onePressed = false;
    }

    if (IsKeyPressed(KEY_TWO) && !twoPressed) {
        ThrowBall((Vector2){player.rect.x + player.rect.width / 2, player.rect.y + player.rect.height / 2}, (Vector2){0, -2}, PURPLE);
        twoPressed = true;
    } else if (IsKeyReleased(KEY_TWO)) {
        twoPressed = false;
    }

    if (IsKeyPressed(KEY_THREE) && !threePressed) {
        ThrowBall((Vector2){player.rect.x + player.rect.width / 2, player.rect.y + player.rect.height / 2}, (Vector2){2, -2}, PURPLE);
        threePressed = true;
    } else if (IsKeyReleased(KEY_THREE)) {
        threePressed = false;
    }

    DrawText(TextFormat("Score: %d", score), 10, 10, 20, BLACK);
    DrawText(TextFormat("High Score: %d", highScore), 10, 40, 20, BLACK);

    if (!player.isAlive) {
        DrawText("Game Over", screenWidth / 2 - MeasureText("Game Over", 40) / 2, screenHeight / 2 - 20, 40, RED);
        DrawText(TextFormat("Score: %d", score), screenWidth / 2 - MeasureText(TextFormat("Score: %d", score), 20) / 2, screenHeight / 2 + 20, 20, BLACK);
        DrawText("Press left mouse button to play again", screenWidth / 2 - MeasureText("Press left mouse button to play again", 20) / 2, screenHeight / 2 + 80, 20, BLACK);
        DrawTexture(endgamebackgroundTexture, 0, 0, WHITE);
    }
    
    EndDrawing();
}

