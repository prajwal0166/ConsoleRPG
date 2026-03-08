#include "StartMenu.h"
#include "CharacterCreation.h"
#include "Game.h"
#include <iostream>
#include <windows.h>

int main() {
    
    SetConsoleOutputCP(CP_UTF8);
    StartMenuChoice choice {showStartMenu()};
    switch(choice) {
        case StartMenuChoice::StartGame: {
            PlayerData player = CreateCharacter();
            StartGame(player);
        }
        break;
            
        break;
        case StartMenuChoice::Exit:
            std::exit(0);
        break;
    }
    
    return 0;
}