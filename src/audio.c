#include "audio.h"

Sound deathSound;
Sound background;

void AddSounds(void) {
    deathSound = LoadSound("deathsound.mp3");
    background = LoadSound("background.mp3");
}

void UnAddSounds(void) {
    UnloadSound(deathSound);
    UnloadSound(background);
}

