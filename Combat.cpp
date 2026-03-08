#include "Combat.h"
#include "Renderer.h"
#include "PlayerUtilities.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <algorithm>

bool StartCombat(Position &playerpos, Enemy &enemy, PlayerData &PlayerData, const int ArenaRows, const int ArenaColumns) {
    bool CombatRunning {true};
    Position ShowAttackTelegraphTile {-1, -1};
    char AttackSymbol {'\0'};
    bool EnemyHit {};
    bool SealedArtifactActive {false};
    bool StaffOfStarsActive {false};
    DWORD SealedArticactStartTime {0};
    DWORD SealedArtifactLastTick {0};
    while(CombatRunning) {
        UpdatePlayer(playerpos, enemy, CombatRunning, PlayerData, EnemyHit, ArenaRows, ArenaColumns, SealedArtifactActive, SealedArticactStartTime, SealedArtifactLastTick, StaffOfStarsActive);
        UpdateEnemy(enemy, playerpos, ShowAttackTelegraphTile, AttackSymbol, PlayerData);
        if (PlayerData.PlayerHP <= 0) {
            std::cout << "YOU DIED\n";
            std::cout << "Press any key to continue...";
            _getch();
            system("cls");
            return false;
        }
        if(enemy.HP <= 0) {
            std::cout << "Enemy Defeated!\n";
            std::cout << "Press any key to continue...";
            _getch();
            system("cls");
            return true;
        }
        if(SealedArtifactActive && PlayerData.Artifact == SealedArtifacts::SeaGodSeptor) {
            DWORD CurrentTime {GetTickCount()};
            if(CurrentTime - SealedArticactStartTime >= 6000) {
                SealedArtifactActive = false;
            } else if(CurrentTime - SealedArtifactLastTick >= 1000) {
                enemy.HP--;
                SealedArtifactLastTick = CurrentTime;
            }
        } else if(SealedArtifactActive && PlayerData.Artifact == SealedArtifacts::LifesCane) {
            DWORD CurrentTime {GetTickCount()};
            if(CurrentTime - SealedArticactStartTime >= 6000) {
                SealedArtifactActive = false;
            } else if(CurrentTime - SealedArtifactLastTick >= 1000) {
                PlayerData.PlayerHP++;
                PlayerData.PlayerHP = std::clamp(PlayerData.PlayerHP, 0, 10);
                SealedArtifactLastTick = CurrentTime;
            }
        }
        RenderArena(playerpos, enemy, ShowAttackTelegraphTile, AttackSymbol, EnemyHit, PlayerData, ArenaRows, ArenaColumns);
        EnemyHit = false;
        Sleep(30);
    }
    return false;
}

void UpdatePlayer(Position &playerpos, Enemy &enemy, bool &CombatRunning, PlayerData &PlayerData, bool &EnemyHit, const int &ArenaRows, const int &ArenaColumns, bool &SealedArtifactActive, DWORD &SealedArticactStartTime, DWORD &SealedArtifactLastTick, bool &StaffOfStarsActive) {
        int newRow {playerpos.row};
        int newCol {playerpos.col};
        if(_kbhit()) {
        int key = _getch();
        if(key == 224) { //movement
            int arrow = _getch();
            if(arrow == 72)
                newRow--;
            if(arrow == 80)
                newRow++;
            if(arrow == 75)
                newCol--;
            if(arrow == 77)
                newCol++;
        } else if(key == 113) { // attack
            bool hit {false};
            PlayerAttack(hit, PlayerData, enemy, playerpos, StaffOfStarsActive);
            if(hit) {
                enemy.HP--;
                EnemyHit = true;
            }
        } else if(key == 104) { //heal
            if(PlayerData.PlayerXP >= 5 && PlayerData.PlayerHP < 10) {
                PlayerData.PlayerXP -= 5;
                PlayerData.PlayerHP +=2;
                PlayerData.PlayerHP = std::clamp(PlayerData.PlayerHP, 0, 10);
            }
        } else if(key == 101) { // use authority
            if(PlayerData.PlayerXP == 15) {
                PlayerData.PlayerXP -= 15;
                UseAuthority(PlayerData, enemy, playerpos, ArenaRows, ArenaColumns);
            }
        } else if(key == 122) { // use sealed artifact
            if(PlayerData.PlayerXP >= 10) {
                PlayerData.PlayerXP -= 10;
                switch(PlayerData.Artifact) {
                    case SealedArtifacts::SeaGodSeptor:
                    {
                        SealedArtifactActive = true;
                        SealedArticactStartTime = GetTickCount();
                        SealedArtifactLastTick = SealedArticactStartTime;
                        break;
                    }
                    case SealedArtifacts::StaffOfStars:
                    {
                        StaffOfStarsActive = true;
                        break;
                    }
                    case SealedArtifacts::LifesCane:
                    {
                        SealedArtifactActive = true;
                        SealedArticactStartTime = GetTickCount();
                        SealedArtifactLastTick = SealedArticactStartTime;
                    }
                }
            }
        }
        if(key == 27)
            CombatRunning = false;
        } 
        newRow = std::clamp(newRow, 0, ArenaRows - 1);
        newCol = std::clamp(newCol, 0, ArenaColumns - 1);
        if(!(newRow == enemy.position.row && newCol == enemy.position.col)) {
            playerpos.row = newRow;
            playerpos.col = newCol;
        }
}

void UpdateEnemy(Enemy &enemy, const Position &playerpos, Position &ShowAttackTelegraphTile, char &AttackSymbol, PlayerData &PlayerData) {
    static DWORD LastEnemyMove {GetTickCount()};
    static bool IsTelegraphing {false};
    static DWORD TelegraphStartTime {0};
    static bool  IsImpacting {false};
    static DWORD ImpactStartTime {0};
    DWORD CurrentTime {GetTickCount()};
    bool PlayerInRange {IsPlayerInRange(enemy, playerpos)};
    if(IsImpacting) {
        AttackSymbol = 'X';
        if(CurrentTime - ImpactStartTime >= 250) {
            IsImpacting = false;
            ShowAttackTelegraphTile = {-1, -1};
            AttackSymbol = '\0';
        }
        return;
    }
    if(IsTelegraphing) {
        AttackSymbol = 'o';
        if(CurrentTime - TelegraphStartTime >= enemy.DodgeWindow) {
            if(playerpos.row == ShowAttackTelegraphTile.row && playerpos.col == ShowAttackTelegraphTile.col) {
                PlayerData.PlayerHP--;
            } else {
                PlayerData.PlayerXP++;
                PlayerData.PlayerXP = std::clamp(PlayerData.PlayerXP, 0 , 15);
            }
            IsTelegraphing = false;
            IsImpacting = true;
            ImpactStartTime = CurrentTime;
            return;
        }
        return;
    }
    if(PlayerInRange) {
        IsTelegraphing = true;
        TelegraphStartTime = CurrentTime;
        ShowAttackTelegraphTile.row = playerpos.row;
        ShowAttackTelegraphTile.col = playerpos.col;
        AttackSymbol = 'o';
        return;
    }
    if(CurrentTime - LastEnemyMove >= enemy.MoveDelay) {
        switch(enemy.type) {
            case EnemyType::Rooster:
            {
                LastEnemyMove = CurrentTime;
                int NewRow {enemy.position.row};
                int NewCol {enemy.position.col};
                int DRow = playerpos.row - enemy.position.row;
                int DCol = playerpos.col - enemy.position.col;
                if(DRow != 0)
                    NewRow += (DRow > 0 ? 1 : -1);
                else if(DCol != 0)
                    NewCol += (DCol > 0 ? 1 : -1);
                if(!(NewRow == playerpos.row && NewCol == playerpos.col)) {
                    enemy.position.row = NewRow;
                    enemy.position.col = NewCol;
                }
            }
                break;
            case EnemyType::Archer:
            {
                int distance = std::abs(playerpos.row - enemy.position.row) + std::abs(playerpos.col - enemy.position.col);
                if(distance > 5) {
                    LastEnemyMove = CurrentTime;
                    int NewRow {enemy.position.row};
                    int NewCol {enemy.position.col};
                    int DRow = playerpos.row - enemy.position.row;
                    int DCol = playerpos.col - enemy.position.col;
                    if(DRow != 0)
                        NewRow += (DRow > 0 ? 1 : -1);
                    else if(DCol != 0)
                        NewCol += (DCol > 0 ? 1 : -1);
                    if(!(NewRow == playerpos.row && NewCol == playerpos.col)) {
                        enemy.position.row = NewRow;
                        enemy.position.col = NewCol;
                    }
                }
            }
                break;
        }
    }
    ShowAttackTelegraphTile = {-1, -1};
    AttackSymbol = '\0';
}