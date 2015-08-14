#ifndef BLINKY_H
#define BLINKY_H
#include <SFML/Graphics.hpp>
#include "ghost.h"


class blinky : public ghost
{
    public:
        blinky();
        blinky(sf::Sprite);
        virtual ~blinky();
        void update(level, pacman, int);
    protected:
    private:
};

#endif // BLINKY_H
