#include "../include/powerpellet.h"

#include <SFML/Graphics.hpp>

powerpellet::powerpellet(sf::Sprite spr)
{
    sprite = spr;
    collision_box = sprite.getGlobalBounds();
}

powerpellet::~powerpellet()
{
    //dtor
}

sf::Sprite powerpellet::get_sprite(){
    return sprite;
}

sf::FloatRect powerpellet::get_collision_box(){
    return collision_box;
}
