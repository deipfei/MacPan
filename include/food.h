#ifndef FOOD_H
#define FOOD_H

#include <SFML/Graphics.hpp>


class food
{
    public:
        food(sf::Sprite, sf::FloatRect);
        virtual ~food();
        sf::Sprite get_sprite();
        sf::FloatRect get_collision_box();
    protected:
        sf::Sprite sprite;
        sf::FloatRect collision_box;
    private:
};

#endif // FOOD_H
