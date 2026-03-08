#ifndef PLAYER_UTILITIES_H
#define PLAYER_UTILITIES_H
#include "Combat.h"

void PlayerAttack(bool &hit, const PlayerData &PlayerData, const Enemy &enemy, const Position &playerpos, bool &StaffOfStarsActive);
void UseAuthority(const PlayerData &PlayerData, Enemy &enemy, Position &playerpos, const int &ArenaRows, const int &ArenaColumns);
bool IsPlayerInRange(const Enemy &enemy, const Position &playerpos);

#endif