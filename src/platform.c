#include "platform.h"
#include "config.h"
#include "raylib.h"

Platform platforms[platformCount];

void StartPlatforms(void) {
    int spacing = 100;

    platforms[0].rect.x = screenWidth/2-50;
    platforms[0].rect.y = screenHeight/2;
    platforms[0].rect.width = 100;
    platforms[0].rect.height = 20;

    for (int i = 1; i < platformCount; i++) {
        platforms[i].rect.x = GetRandomValue(0, screenWidth - 100);
        platforms[i].rect.y = platforms[i-1].rect.y-spacing;
        platforms[i].rect.width = 100;
        platforms[i].rect.height = 20;
        platforms[i].isActive = true;
        platforms[i].firstJump = false;
    }
}

void UpdatePlatforms(void) {
    for (int i = 0; i < platformCount; i++) {
        platforms[i].rect.y += platformSpeed;
        
        if (platforms[i].rect.y > screenHeight) {
            platforms[i].rect.y = -50;
            platforms[i].rect.x = GetRandomValue(0, screenWidth - 100);
        }
    }
}

