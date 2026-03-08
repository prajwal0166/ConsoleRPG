#include "NavigationSystem.h"
#include "Renderer.h"
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <windows.h>


int RunNavigation(const NavigationKeys &scheme, const std::vector<std::string> &Options, const std::string Heading, const bool UseNewLineAfterHeading, const int OptionsSpacing) {
    size_t selection {0};
    while(true) {
        system("cls");
        std::cout << Heading << (UseNewLineAfterHeading? "\n":"");
        for(size_t i = 0; i < Options.size(); i++) {
            if(i == selection)
                std::cout << std::setw(OptionsSpacing) << "▶ " << Options.at(i) << (UseNewLineAfterHeading? "\n":"");
            else
                std::cout << std::setw(OptionsSpacing) << " " << Options.at(i) << (UseNewLineAfterHeading? "\n":"");
        }
        int PrefixUserinput = _getch();
        if(PrefixUserinput == scheme.prefix) {
            int SuffixUserinput = _getch();
            if(SuffixUserinput == scheme.key1 && selection > 0)
                selection--;
            else if(SuffixUserinput == scheme.key2 && selection < Options.size() - 1)
                selection++;
        } else if(PrefixUserinput == 13) {
            system("cls");
            return static_cast<int>(selection);
        }
    }
}

int RunNavigation(const NavigationKeys &scheme, const std::vector<std::string> &Options, const int OptionsSpacing) {
    size_t selection {0};
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    SHORT menuRow = csbi.dwCursorPosition.Y;
    while(true) {
        RenderMenu(Options, selection, OptionsSpacing, menuRow);
        int PrefixUserinput = _getch();
        if(PrefixUserinput == scheme.prefix) {
            int SuffixUserinput = _getch();
            if(SuffixUserinput == scheme.key1 && selection > 0)
                selection--;
            else if(SuffixUserinput == scheme.key2 && selection < Options.size() - 1)
                selection++;
        } else if(PrefixUserinput == 13) {
            SetConsoleCursorPosition(hConsole, {0, menuRow});
            std::cout << std::string(2000, ' ');
            SetConsoleCursorPosition(hConsole, {0, menuRow});
            return static_cast<int>(selection);
        }
    }
}