#include "CharacterAttributes.h"
#include <iostream>

std::ostream &operator<<(std::ostream &os, Gender choice) {
    switch(choice) {
        case Gender::Male:
            return os << "Male";
            break;
        case Gender::Female:
            return os << "Female";
            break;
        default:
            return os << "Unknown";
    }
}

std::ostream &operator<<(std::ostream &os, Pathway choice) {
    switch(choice) {
        case Pathway::Fool:
            return os << "Fool";
            break;
        case Pathway::Error:
            return os << "Error";
            break;
        case Pathway::Door:
            return os << "Door";
            break;
        default:
            return os << "Unknown";
    }
}

std::string ToString(SealedArtifacts Artifact) {
    switch(Artifact) {
        case SealedArtifacts::SeaGodSeptor:
            return "Sea God Septor";
            break;
        case SealedArtifacts::StaffOfStars:
            return "Staff of Stars";
            break;
        case SealedArtifacts::LifesCane:
            return "Life's Cane";
            break;
        default:
            return "Unknown";
    }
}