#ifndef INKY_H
#define INKY_H

#include <SFML/Graphics.hpp>
#include "../include/level.h"
#include "../include/pacman.h"
#include "../include/ghost.h"
#include "../include/blinky.h"

class inky : public ghost
{
    public:
        inky();
        inky(sf::Sprite);
        virtual ~inky();
        void update(level, pacman, blinky, int);
    protected:
    private:
};

#endif // INKY_H
