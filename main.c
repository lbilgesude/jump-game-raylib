#include "raylib.h"
#include "src/config.h"
#include "src/game.h"
#include "src/menu.h"
#include "src/player.h"
#include "src/platform.h"
#include "src/monster.h"
#include "src/graphics.h"
#include "src/audio.h"

int main() {
    InitWindow(screenWidth, screenHeight, "Doodle Jump");
    InitAudioDevice();
    SetTargetFPS(60);
    AddSounds();
    
    bool gameOver = false;
    bool playAgain = false;
    bool showMenu = true;

    while (!WindowShouldClose() && !gameOver) {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
            PlaySound(deathSound);
            PlaySound(background);
        }
        if(showMenu) {
            showMenu = !ShowMenuScreen();
            if (!showMenu) {
                StartGame();
                score = 0;
            }
        }

        while (!playAgain && !WindowShouldClose()) {
            UpdateGame();
            UpdatePlatforms();
            UpdateMonsters();

            DrawGame();

            if (!player.isAlive) {
                while (!IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !WindowShouldClose()) {
                    DrawText("Game Over", screenWidth/2 - MeasureText("Game Over", 40)/2, screenHeight/2 - 20, 40, RED);
                    DrawText(TextFormat("Score: %d", score), screenWidth/2 - MeasureText(TextFormat("Score: %d", score), 20)/2, screenHeight/2 + 20, 20, BLACK);
                    DrawText("Press left mouse button to play again", screenWidth/2 - MeasureText("Press left mouse button to play again", 20)/2, screenHeight/2 + 80, 20, BLACK);
                    EndDrawing();
                }
                playAgain = true;
            }
        }

        if (playAgain) {
            gameOver = false;
            playAgain = false;
            showMenu = true;
        }
    }

    UnAddGraph();
    UnAddSounds();

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
