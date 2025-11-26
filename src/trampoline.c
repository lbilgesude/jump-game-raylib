#include "trampoline.h"
#include "platform.h"
#include "config.h"
#include "raylib.h"

Trampoline trampolines[platformCount/2];

void InitTrampolines(void) {
    for (int i = 0; i < platformCount / 2; i++) {
        if (i == 0)
            continue;

        trampolines[i].rect.x = platforms[i].rect.x + (platforms[i].rect.width - trampolines[i].rect.width) / 2;
        trampolines[i].rect.y = platforms[i].rect.y - trampolines[i].rect.height;
        trampolines[i].rect.width = 50;
        trampolines[i].rect.height = 20;
        trampolines[i].color = YELLOW;
        trampolines[i].isActive = true;
        trampolines[i].firstJump = false;
    }
}

void UpdateTrampolines(void) {
    for (int i = 0; i < platformCount / 2; i++) {
        trampolines[i].rect.x = platforms[i].rect.x + (platforms[i].rect.width - trampolines[i].rect.width) / 2;
        trampolines[i].rect.y = platforms[i].rect.y - trampolines[i].rect.height;
    }
}

