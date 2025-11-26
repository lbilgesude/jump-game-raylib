#include "graphics.h"
#include "config.h"

Texture2D playerTexture;
Texture2D platformTexture;
Texture2D trampolineTexture;
Texture2D monsterTexture;
Texture2D backgroundTexture;
Texture2D endgamebackgroundTexture;

void MakeOval(Rectangle rec, Color color) {
    DrawEllipse(rec.x + rec.width / 2, rec.y + rec.height / 2, rec.width / 2, rec.height / 2, color);
}

void AddGraph(void) {
    Image playerImage = LoadImage("karakter.png");
    ImageResize(&playerImage, playerWidth, playerHeight);
    playerTexture = LoadTextureFromImage(playerImage);
    UnloadImage(playerImage);

    Image platformImage = LoadImage("platform.png");
    ImageResize(&platformImage, platformWidth, platformHeight);
    platformTexture = LoadTextureFromImage(platformImage);
    UnloadImage(platformImage);

    Image trampolineImage = LoadImage("trampoline.png");
    ImageResize(&trampolineImage, trampolineWidth, trampolineHeight);
    trampolineTexture = LoadTextureFromImage(trampolineImage);
    UnloadImage(trampolineImage);

    Image monsterImage = LoadImage("monsters.png");
    ImageResize(&monsterImage, monsterWidth, monsterHeight);
    monsterTexture = LoadTextureFromImage(monsterImage);
    UnloadImage(monsterImage);

    Image backgroundImage = LoadImage("background.png");
    backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);
    
    Image endgamebackgroundImage = LoadImage("endgamebackground.png");
    endgamebackgroundTexture = LoadTextureFromImage(endgamebackgroundImage);
    UnloadImage(endgamebackgroundImage);
}

void UnAddGraph(void) {
    UnloadTexture(playerTexture);
    UnloadTexture(platformTexture);
    UnloadTexture(trampolineTexture);
    UnloadTexture(monsterTexture);
    UnloadTexture(backgroundTexture);
    UnloadTexture(endgamebackgroundTexture);
}


