#include "monster.h"
#include "config.h"
#include "platform.h"
#include "trampoline.h"
#include "raylib.h"

Monster Monsters[monsterCount];

void InitMonsters(void) {
    for (int i = 0; i < monsterCount; i++) {
        Monsters[i].rect.x = GetRandomValue(0, screenWidth - 50);
        Monsters[i].rect.y = GetRandomValue(-1000, -50);
        Monsters[i].rect.width = 50;
        Monsters[i].rect.height = 50;
    }
}

void UpdateMonsters(void) {
    for (int i = 0; i < monsterCount; i++) {
        Monsters[i].rect.y += platformSpeed;
        
        if (Monsters[i].rect.y > screenHeight) {
            Monsters[i].rect.y = -50;
            Monsters[i].rect.x = GetRandomValue(0, screenWidth - 50);
        }
    
        for (int j = 0; j < platformCount; j++) {
            if (CheckCollisionRecs(Monsters[i].rect, platforms[j].rect)) {
                Monsters[i].rect.y = -50;
                Monsters[i].rect.x = GetRandomValue(0, screenWidth - 50);
            }
        }
        for (int j = 0; j < platformCount / 2; j++) {
            if (trampolines[j].isActive && CheckCollisionRecs(Monsters[i].rect, trampolines[j].rect)) {
                Monsters[i].rect.y = -50;
                Monsters[i].rect.x = GetRandomValue(0, screenWidth - 50);
            }
        }
    }
}

