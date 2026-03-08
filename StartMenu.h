#ifndef START_MENU_H
#define START_MENU_H
#include <iostream>

enum class StartMenuChoice {
    StartGame = 0, Exit = 1
};
std::ostream &operator<<(std::ostream& os, StartMenuChoice choice);
StartMenuChoice showStartMenu();

#endif