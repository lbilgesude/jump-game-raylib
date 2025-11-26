#include "menu.h"
#include "graphics.h"
#include "config.h"
#include "raylib.h"

bool ShowMenuScreen(void) {
    Texture2D backgroundTexture = LoadTexture("menubackground.png");

    Rectangle playButton = { screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50 };
    Rectangle settingsButton = { screenWidth / 2 - 100, screenHeight / 2 + 30, 200, 50 };
    Rectangle helpButton = { screenWidth / 2 - 100, screenHeight / 2 + 110, 200, 50 };

    while (!WindowShouldClose()) {
        BeginDrawing();

        DrawTexture(backgroundTexture, 0, 0, WHITE);

        MakeOval(playButton, DARKBLUE);
        MakeOval(settingsButton, GRAY);
        MakeOval(helpButton, GRAY);

        DrawText("Play", playButton.x + 70, playButton.y + 15, 20, WHITE);
        DrawText("Settings", settingsButton.x + 50, settingsButton.y + 15, 20, WHITE);
        DrawText("Help", helpButton.x + 70, helpButton.y + 15, 20, WHITE);

        EndDrawing();

        if (CheckCollisionPointRec(GetMousePosition(), playButton)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                UnloadTexture(backgroundTexture);
                return true;
            }
        } else if (CheckCollisionPointRec(GetMousePosition(), settingsButton)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Ayarlar ekranını aç
            }
        } else if (CheckCollisionPointRec(GetMousePosition(), helpButton)) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // Yardım ekranını aç
            }
        }
    }

    UnloadTexture(backgroundTexture);
    return false;
}

