#ifndef RENDERER_H
#define RENDERER_H
#include "Combat.h"
#include <vector>
#include <windows.h>
#include <string>

void RenderMenu(const std::vector<std::string> &options, const size_t selection, const int OptionsSpacing, const SHORT row);
void TypeText(const std::string &text, int DelayInMs);
void RenderArena(const Position &playerpos, const Enemy &enemy, Position &ShowAttackTelegraphTile, char &AttackSymbol, bool &EnemyHit, const PlayerData &PlayerData, const int &ArenaRows, const int &ArenaColumns);

#endif