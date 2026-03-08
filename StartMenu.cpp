#include "StartMenu.h"
#include "NavigationSystem.h"
#include <vector>
#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>

StartMenuChoice showStartMenu() {
        std::vector<std::string> startMenuOptions {
        "Start Game",
        "Exit"
    };
    int choice {RunNavigation(NavSchemes::Vertical, startMenuOptions, "-------------LORD OF THE BROKEN-------------", true, 0)};
    return static_cast<StartMenuChoice>(choice);
}

std::ostream &operator<<(std::ostream &os, StartMenuChoice choice) {
    switch (choice) {
        case StartMenuChoice::StartGame:
            return os << "StartGame";
        case StartMenuChoice::Exit:
            return os << "Exit";
        default:
            return os << "Unknown";
    }
}