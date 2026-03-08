#ifndef PLAYER_DATA_H
#define PLAYER_DATA_H
#include <string>
#include "CharacterAttributes.h"

struct PlayerData {
    std::string name;
    Gender gender;
    Pathway pathway;
    SealedArtifacts Artifact;
    int PlayerHP {10};
    int PlayerXP {0};
};

#endif