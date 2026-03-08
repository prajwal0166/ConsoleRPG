#include "Game.h"
#include "CharacterCreation.h"
#include "NavigationSystem.h"
#include "Renderer.h"
#include "Combat.h"
#include "Entities.h"
#include "CharacterAttributes.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <sstream>
#include <vector>

void StartGame(PlayerData &player) {
    system("cls");
    std::stringstream oss;
    oss << player.pathway;
    std::string pathway {oss.str()};
    std::string HerOHis {(player.gender == Gender::Male) ? "his" : "her"};
    std::string CHeOShe {(player.gender == Gender::Male) ? "He" : "She"};
    std::string HeOShe {(player.gender == Gender::Male) ? "he" : "she"};
    std::string HimOHer {(player.gender == Gender::Male) ? "him" : "her"};
    TypeText(player.name + " woke up from the noises outside " + HerOHis + " window", 1);
    std::cout << "\n";
    
    std::vector<std::string> choices {"Check out from the window", "Ignore the noises and goto sleep"};
    int choice {RunNavigation(NavSchemes::Horizontal, choices, 10)};
    if(choice == 0) {
        TypeText(HeOShe + " went to the window to check what is happening outside and the sight shattered " + HerOHis + " sleep. People were running in terror it looks like a high alert situation or some beyonder who are of high sequence lost their control.", 1);
        TypeText(player.name + " went to the cupboard and opened to take out "+ HerOHis +" sealed artifacts. I think there is a hight alert I should take my sealed artifacts and head to saint samuel's cthedral as soon as possible.", 1);
        TypeText("Ahh! Fuck I can carry only one sealed artifact I cannot carry more than 1. There are total 3 with me which ones should I carry \n", 1);
        std::vector<SealedArtifacts> Artifacts {
            SealedArtifacts::SeaGodSeptor,
            SealedArtifacts::StaffOfStars,
            SealedArtifacts::LifesCane
        };
        std::vector<std::string> ArtifactNames;
        for(auto Artifact : Artifacts)
            ArtifactNames.push_back(ToString(Artifact));
        int choiceIndex {RunNavigation(NavSchemes::Horizontal, ArtifactNames, 5)};
        SealedArtifacts ChosenArtifact {Artifacts[choiceIndex]};
        player.Artifact = static_cast<SealedArtifacts>(ChosenArtifact);
        if(ChosenArtifact == SealedArtifacts::SeaGodSeptor) {
            TypeText("This is perfect the sea god septor it lets me use the powers of lightning domain", 1);
        } else if(ChosenArtifact == SealedArtifacts::StaffOfStars) {
            TypeText("This is perfect the staff of stars it lets me copy the powers of other beyonders", 1);
        } else {
            TypeText("This is perfect the life's cane it lets me use the power of reproduction and also infect other beyonders and make them mutate", 1);
        }
        TypeText(player.name + "turned toward the door and quickly came out of " + HerOHis + " room and the building began to shake and all of a sudden a mutated chicken rooster appeared in front of hi which has been infected by some beyonder charisteristic \n", 1);
        TypeText("The creature lunged forward and attacked " + player.name, 1);
        TypeText("\nHit Enter to fight the checken", 1);
        while(true) {
            int c = _getch();
            if(c == 13) {
                Position PlayerPosition {1, 0};
                Enemy enemy {
                    EnemyType::Rooster,
                    {1, 4},
                    5,
                    500,
                    1000,
                    'E'
                };
                bool PlayerWon {StartCombat(PlayerPosition, enemy, player, 3, 5)};
                if(PlayerWon) {
                    break;
                } else {
                    std::cout << "GAME OVER\n";
                    std::exit(0);
                }
            } else if(c == 27) {
                break;
            }
        }
    TypeText(player.name + " defeated the mutated rooster and stepped into the street there so many people are running and suddenly from top of a building another rooster lunged on his. This looks more aggresive than the previous one", 1);
    while(true) {
            int c = _getch();
            if(c == 13) {
                Position PlayerPosition {1, 0};
                Enemy enemy {
                    EnemyType::Rooster,
                    {1, 4},
                    10,
                    250,
                    500,
                    'E'
                };
                bool PlayerWon {StartCombat(PlayerPosition, enemy, player, 6, 10)};
                if(PlayerWon) {
                    break;
                } else {
                    std::cout << "GAME OVER\n";
                    std::exit(0);
                }
            } else if(c == 27) {
                break;
            }
    }
    TypeText("This one is a tough one I have to move on. " + player.name + " headed to the Weightstone bridge and found a mman eating the corpses , " + player.name + " walked silently from beside the man and then suddenly the man lunged on " + player.name + " attacking him", 1);
    while(true) {
            int c = _getch();
            if(c == 13) {
                Position PlayerPosition {1, 0};
                Enemy enemy {
                    EnemyType::Archer,
                    {1, 5},
                    20,
                    125,
                    250,
                    'E'
                };
                bool PlayerWon {StartCombat(PlayerPosition, enemy, player, 12, 20)};
                if(PlayerWon) {
                    break;
                } else {
                    std::cout << "GAME OVER\n";
                    std::exit(0);
                }
            } else if(c == 27) {
                break;
            }
    }
    TypeText(CHeOShe + " defeated the lost control beyonder and reached saints avenue. There are two ways one on the road but on which the beyonder creatures are roaming and one is from the rooftops.", 1);
    std::vector<std::string> choices {"Go from the street", "go from the rooftop"};
    int choice {RunNavigation(NavSchemes::Horizontal, choices, 10)};
    if(choice == 0) {
        TypeText("You Successfully reached saint samuel's cathedral you won", 1);
    } else {
        TypeText("Somehow you died and did not make it to the cathedra", 1);
    }
    } else {
        TypeText(CHeOShe + " went back to sleep covering " + HerOHis + " face with blanket.", 1);
        TypeText("Soon the building began to shake and " + player.name + " died as the ceiling fan fell on " + HerOHis + " head from the vibrations.", 1);
    }
}