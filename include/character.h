#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include "../include/level.h"

class character
{
    public:
        character();
        virtual ~character();
        sf::Sprite get_sprite();
        sf::FloatRect get_collision_box();
        float get_xpos();
        float get_ypos();
        void step_back();
        void set_position(float, float);
    protected:
        sf::Sprite sprite;
        sf::FloatRect collision_box;
        float xpos;
        float ypos;
        float xvel;
        float yvel;
    private:

};

#endif // CHARACTER_H
