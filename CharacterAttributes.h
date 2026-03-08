#ifndef CHARACTER_ATTRIBUTES_H
#define CHARACTER_ATTRIBUTES_H
#include <string>

enum class Gender {
    Male = 0, Female = 1
};
enum class Pathway {
    Fool = 0, Error = 1, Door = 2
};
enum class SealedArtifacts {
    SeaGodSeptor = 0, StaffOfStars = 1, LifesCane = 2
};
std::string ToString(SealedArtifacts Artifact);
std::ostream &operator<<(std::ostream &os, Pathway choice);
std::ostream &operator<<(std::ostream &os, Gender choice);

#endif