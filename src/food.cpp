#include "../include/food.h"
#include <SFML/Graphics.hpp>

food::food(sf::Sprite spr, sf::FloatRect c)
{
   sprite = spr;
   collision_box = c;
}

food::~food()
{
    //dtor
}

sf::Sprite food::get_sprite(){
    return sprite;
}

sf::FloatRect food::get_collision_box(){
    return collision_box;
}
