#include "../include/character.h"
#include <SFML/Graphics.hpp>
#include <cmath>

sf::Sprite sprite;
sf::FloatRect collision_box;
float xpos;
float ypos;

character::character()
{
    //ctor
}

character::~character()
{
    //dtor
}

sf::Sprite character::get_sprite(){
    return sprite;
}

sf::FloatRect character::get_collision_box(){
    return collision_box;
}

float character::get_xpos(){
    return xpos;
}

float character::get_ypos(){
    return ypos;
}

void character::step_back(){
    xpos -= xvel;
    ypos -= yvel;
    sprite.setPosition(sf::Vector2f(xpos, ypos));
    collision_box = sprite.getGlobalBounds();
}

void character::set_position(float x, float y){
    xpos = x;
    ypos = y;
    sprite.setPosition(sf::Vector2f(xpos, ypos));
    collision_box = sprite.getGlobalBounds();
}
