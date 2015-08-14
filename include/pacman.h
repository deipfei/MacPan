#ifndef PACMAN_H
#define PACMAN_H

#include "character.h"
#include "Animation.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>


class pacman : public character
{
    public:
        pacman(sf::Texture);
        virtual ~pacman();
        void update();
        void set_xpos(float);
        void set_ypos(float);
        void set_xvel(float);
        void set_yvel(float);
        void set_dir(int);
        int get_dir();
        void set_pos(float, float);
        Animation* get_curr_anim();
        void set_curr_anim(int);
        AnimatedSprite get_anspr();
    protected:
        int dir;

    private:
};

#endif // PACMAN_H
