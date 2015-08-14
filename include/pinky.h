#ifndef PINKY_H
#define PINKY_H

#include "../include/ghost.h"
#include "../include/level.h"
#include "../include/pacman.h"
#include <SFML/Graphics.hpp>

class pinky : public ghost
{
    public:
        pinky();
        pinky(sf::Sprite);
        virtual ~pinky();
        void update(level, pacman, int);
    protected:
    private:
};

#endif // PINKY_H
