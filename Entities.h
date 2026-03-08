#ifndef ENTITIES_H
#define ENTITIES_H
#include "Position.h"

enum class EnemyType {
    Rooster,
    Archer
};

struct Enemy {
    EnemyType type;
    Position position;
    int HP;
    int MoveDelay;
    int DodgeWindow;
    char Symbol;
};

#endif