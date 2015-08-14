#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "AnimatedSprite.h"


class mainmenu
{
    public:
        mainmenu();
        mainmenu(sf::Sprite, Animation, Animation);
        virtual ~mainmenu();
        void update();
        AnimatedSprite getGhosts();
        AnimatedSprite getSpace();
        sf::Sprite getBackground();
    protected:
        AnimatedSprite ghosts;
        AnimatedSprite space;
        Animation ghostsanim;
        Animation spaceanim;
        sf::Clock frame_time;
        sf::Sprite background;
    private:
};

#endif // MAINMENU_H
