#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

extern Player player;

void InitPlayer(void);
void UpdatePlayerMovement(void);
void UpdatePlayerPhysics(void);
void CheckPlayerCollisions(void);
void CheckPlayerBounds(void);

#endif // PLAYER_H

