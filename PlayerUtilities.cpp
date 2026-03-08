#include "PlayerUtilities.h"

void PlayerAttack(bool &hit, const PlayerData &PlayerData, const Enemy &enemy, const Position &playerpos, bool &StaffOfStarsActive) {
    if(StaffOfStarsActive) {
        switch(enemy.type) {
            case EnemyType::Rooster:
            {
                hit = (playerpos.row == enemy.position.row && abs(playerpos.col - enemy.position.col) == 1) || (playerpos.col == enemy.position.col && abs(playerpos.row - enemy.position.row) == 1);
            }
                break;
            case EnemyType::Archer:
            {
                hit = (abs(playerpos.row - enemy.position.row) + abs(playerpos.col - enemy.position.col) <= 5);
            }
                break;
        }
        if(hit) {
                StaffOfStarsActive = false;
            }
        return;
    } else {
        switch(PlayerData.pathway) {
                case Pathway::Fool:
                    hit = (abs(playerpos.row - enemy.position.row) == 1 && abs(playerpos.col - enemy.position.col) == 1);
                    break;
                case Pathway::Error:
                    hit = (playerpos.row == enemy.position.row && abs(playerpos.col - enemy.position.col) == 1) || (playerpos.col == enemy.position.col && abs(playerpos.row - enemy.position.row) == 1);
                    break;
                case Pathway::Door:
                    hit = (playerpos.row == enemy.position.row) || (playerpos.col == enemy.position.col);
                    break;
        }
    }
}

void UseAuthority(const PlayerData &PlayerData, Enemy &enemy, Position &playerpos, const int &ArenaRows, const int &ArenaColumns) {
    switch(PlayerData.pathway) {
                    case Pathway::Fool:
                    {
                        enemy.HP = 0;
                    }
                        break;
                    case Pathway::Error:
                    {
                        int TempRow = playerpos.row;
                        int TempCol = playerpos.col;
                        playerpos.row = enemy.position.row;
                        playerpos.col = enemy.position.col;
                        enemy.position.row = TempRow;
                        enemy.position.col = TempCol;
                    }
                        break;
                    case Pathway::Door:
                    {
                        int BestRow = enemy.position.row;
                        int BestCol = enemy.position.col;
                        int MaxDistance {-1};
                        for(int r = 0; r < ArenaRows; r++) {
                            for(int c = 0; c < ArenaColumns; c++) {
                                int Distance = abs(playerpos.row - r) + abs(playerpos.col - c);
                                if(Distance > MaxDistance) {
                                    MaxDistance = Distance;
                                    BestRow = r;
                                    BestCol = c;
                                }
                            }
                        }
                        enemy.position.row = BestRow;
                        enemy.position.col = BestCol;
                    }
                        break;
                }
}

bool IsPlayerInRange(const Enemy &enemy, const Position &playerpos) {
    int dRow {playerpos.row - enemy.position.row};
    int dCol {playerpos.col - enemy.position.col};
    switch(enemy.type) {
        case EnemyType::Rooster:
            return std::abs(dRow) + std::abs(dCol) == 1;
        case EnemyType::Archer:
            return std::abs(dRow) + std::abs(dCol) <= 5;
        default:
            return false;
    }
}