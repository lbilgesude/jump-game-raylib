#include "player.h"
#include "config.h"
#include "platform.h"
#include "trampoline.h"
#include "monster.h"
#include "audio.h"
#include "raylib.h"

Player player;

void InitPlayer(void) {
    player.rect.x = screenWidth / 2 - playerWidth / 2;
    player.rect.y = screenHeight / 2 - playerHeight / 2;
    player.rect.width = playerWidth;
    player.rect.height = playerHeight;
    player.velocity = (Vector2){ 0, 0 };
    player.isJumping = false;
    player.isAlive = true;
    player.platformJumped = false;
}

void UpdatePlayerMovement(void) {
    if (IsKeyDown(KEY_RIGHT) && player.isAlive) {
        player.rect.x += moveSpeed;
    } else if (IsKeyDown(KEY_LEFT) && player.isAlive) {
        player.rect.x -= moveSpeed;
    }
}

void UpdatePlayerPhysics(void) {
    player.velocity.y += gravity;
    player.rect.y += player.velocity.y;
}

void CheckPlayerCollisions(void) {
    extern int score;
    
    // Platform collision
    for (int i = 0; i < platformCount; i++) {
        if (CheckCollisionRecs(player.rect, platforms[i].rect)) {
            if (player.velocity.y > 0 && !player.isJumping && !player.platformJumped) {
                player.isJumping = true;
                player.platformJumped = true;
            }   
            player.velocity.y = jumpForce;
            if (!platforms[i].firstJump) {
                score += 10;
                platforms[i].firstJump = true;
            }
        } else {
            player.platformJumped = false;
        }
    }

    // Trampoline collision
    for (int i = 0; i < platformCount / 3; i++) {
        if (trampolines[i].isActive && CheckCollisionRecs(player.rect, trampolines[i].rect)) {
            player.velocity.y = trampolineForce;
            player.isJumping = true;
            if (!trampolines[i].firstJump) {
                score += 20;
                trampolines[i].firstJump = true;
            }
        }
    }

    // Monster collision
    for (int i = 0; i < monsterCount; i++) {
        if (CheckCollisionRecs(player.rect, Monsters[i].rect)) {
            player.isAlive = false;
            PlaySound(deathSound);
        }
    }
}

void CheckPlayerBounds(void) {
    if (player.rect.x > screenWidth) {
        player.rect.x = -player.rect.width;
    } else if (player.rect.x + player.rect.width < 0) {
        player.rect.x = screenWidth;
    }

    if (player.rect.y > screenHeight && player.isAlive) {
        player.isAlive = false;
        PlaySound(deathSound);
    }
}

