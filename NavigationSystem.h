#ifndef NAVIGATION_SYSTEM_H
#define NAVIGATION_SYSTEM_H
#include <vector>
#include <string>

struct NavigationKeys {
    int key1;
    int key2;
    int prefix;
};

namespace NavSchemes {
    constexpr NavigationKeys Vertical {
        72,
        80,
        224
    };
    constexpr NavigationKeys Horizontal {
        75,
        77,
        224
    };
}
int RunNavigation(const NavigationKeys &scheme, const std::vector<std::string> &Options, const std::string Heading, const bool UseNewLineAfterHeading, const int OptionsSpacing);
int RunNavigation(const NavigationKeys &scheme, const std::vector<std::string> &Options, const int OptionsSpacing);

#endif