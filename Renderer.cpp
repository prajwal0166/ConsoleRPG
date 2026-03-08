#include "Renderer.h"
#include "Combat.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <iomanip>

void RenderMenu(const std::vector<std::string> &options, const size_t selection, const int OptionsSpacing, const SHORT row) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hConsole, {0, row});
    std::cout << std::string(2000, ' ');
    SetConsoleCursorPosition(hConsole, {0, row});
    for(size_t i = 0; i < options.size(); i++) {
        if(i == selection)
                std::cout << std::setw(OptionsSpacing) << "▶ " << options.at(i);
            else
                std::cout << std::setw(OptionsSpacing) << " " << options.at(i);
    }
}

void TypeText(const std::string &text, int DelayInMs) {
    for(char c:text) {
        std::cout << c << std::flush;
        Sleep(DelayInMs);
    }
}

void RenderArena(const Position &playerpos, const Enemy &enemy, Position &ShowAttackTelegraphTile, char &AttackSymbol, bool &EnemyHit, const PlayerData &PlayerData, const int &ArenaRows, const int &ArenaColumns) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    for(int row = 0; row < ArenaRows; row++) {
        for(int col = 0; col < ArenaColumns; col++) {
            if(row == ShowAttackTelegraphTile.row && col == ShowAttackTelegraphTile.col) {
                std::cout << AttackSymbol <<" ";
            } else if(enemy.position.row == row && enemy.position.col == col) {
                if(EnemyHit)
                    SetConsoleTextAttribute(hConsole, 12);
                std::cout << enemy.Symbol << " ";
                SetConsoleTextAttribute(hConsole, 7);
            } else if (playerpos.row == row && playerpos.col == col)
                std::cout << "P ";
            else
                std::cout << ". ";
        }
        std::cout << "\n";
    }
    std::cout << "Player HP: " << PlayerData.PlayerHP << "/10" << " " << "Enemy HP: " << enemy.HP << " " << "Player XP: " << PlayerData.PlayerXP << "/15" << "\n";
}