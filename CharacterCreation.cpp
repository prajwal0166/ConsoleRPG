#include "CharacterCreation.h"
#include "NavigationSystem.h"
#include <conio.h>
#include <windows.h>
#include <vector>
#include <iomanip>

std::string GetCharacterName() {
    std::string CharacterName;
    HANDLE ConsoleColor = GetStdHandle(STD_OUTPUT_HANDLE);
    bool ShowCharacterNameCharacterLimitWarning {false};
    while(true) {
        system("cls");
        
        std::cout << "Bestow a name for your character: " << CharacterName;
        std::cout << "[" << CharacterName.length() << "/" << 250 << "]" << std::endl;
        
        if(ShowCharacterNameCharacterLimitWarning) {
           std::cout << "Character name exceeds the limit.";
        }
        
        char ch = _getch();
        
        if(CharacterName.length() == 250 && isprint(static_cast<unsigned char>(ch))) {
            SetConsoleTextAttribute(ConsoleColor, 12);
            ShowCharacterNameCharacterLimitWarning = true;
        } else {
            SetConsoleTextAttribute(ConsoleColor, 7);
            ShowCharacterNameCharacterLimitWarning = false;
        }
        
        if((int)ch == 8) {
            if(CharacterName.length() > 0) {
                CharacterName.pop_back();
            }            
        }
        
        if((int)ch == 13) {
            if(CharacterName.length() == 0) {
                std::cout << "\nCharacter name cannot be empty" << std::endl;
                std::cout << "Press Enter to continue" << std::endl;
                while(_getch() != 13) {
                    continue;
                }
            } else {
                return CharacterName;
            }
        }
        
        if(isprint(static_cast<unsigned char>(ch)) && CharacterName.length() < 250) {
            CharacterName.push_back(ch);
        }
    }
}

Gender GetCharacterGender() {
    std::vector<std::string> Genders {
        "Male",
        "Female"
    };
    int choice {RunNavigation(NavSchemes::Horizontal, Genders, "Choose gender: ", false, 10)};
    return static_cast<Gender>(choice);
}

Pathway GetCharacterPathway() {
    std::vector<std::string> Pathways {
        "Fool", "Error", "Door"
    };
    int choice {RunNavigation(NavSchemes::Horizontal, Pathways, "Choose your pathway: ", false, 10)};
    return static_cast<Pathway>(choice);
}

PlayerData CreateCharacter() {
    while(true) {
        system("cls");
        PlayerData player;
        player.name = GetCharacterName();
        player.gender = GetCharacterGender();
        player.pathway = GetCharacterPathway();
        std::cout << "Your Character details are: " << std::endl;
        std::cout << "Name: " << player.name << std::endl;
        std::cout << "Gender: " << player.gender << std::endl;
        std::cout << "Pathway: " << player.pathway << std::endl;
        std::cout << "Hit Enter to confirm or Esc to edit" << std::endl;
        int KeyPressed = _getch();
        if(KeyPressed == 13) {
            return player;
        }
        if(KeyPressed == 27) {
            continue;
        }
    }
}