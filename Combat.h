#ifndef COMBAT_H
#define COMBAT_H
#include "Position.h"
#include "CharacterAttributes.h"
#include "PlayerData.h"
#include "Entities.h"
#include <windows.h>
bool StartCombat(Position &playerpos, Enemy &enemy, PlayerData &PlayerData, const int ArenaRows, const int ArenaColumns);
void UpdatePlayer(Position &playerpos, Enemy &enemy, bool &CombatRunning, PlayerData &PlayerData, bool &EnemyHit, const int &ArenaRows, const int &ArenaColumns, bool &SealedArtifactActive, DWORD &SealedArticactStartTime, DWORD &SealedArtifactLastTick, bool &StaffOfStarsActive);
void UpdateEnemy(Enemy &enemy, const Position &playerpos, Position &ShowAttackTelegraphTile, char &AttackSymbol, PlayerData &PlayerData);

#endif