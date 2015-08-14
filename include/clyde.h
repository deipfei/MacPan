#ifndef CLYDE_H
#define CLYDE_H

#include "../include/ghost.h"
#include "../include/level.h"
#include "../include/pacman.h"
#include <SFML/Graphics.hpp>


class clyde : public ghost
{
    public:
        clyde();
        clyde (sf::Sprite);
        virtual ~clyde();
        void update(level, pacman, int);
    protected:
    private:
};

#endif // CLYDE_H
