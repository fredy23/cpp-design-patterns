#include <iostream>

#include "wild_west_game.hpp"
#include "space_game.hpp"

int main()
{
    std::cout << "Playing wild west game\n\n";

    WildWestGame wildWestGame {};
    wildWestGame.play();

    std::cout << "\nPlaying space game\n\n";

    SpaceGame spaceGame {};
    spaceGame.play();
}
