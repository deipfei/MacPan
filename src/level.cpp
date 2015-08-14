#include "../include/level.h"
#include <SFML/Graphics.hpp>

std::vector<sf::RectangleShape> pieces;
std::vector<sf::FloatRect> collisions;
std::vector<sf::FloatRect> food_collisions;
std::vector<sf::Vector2f> power_pellets;

level::level()
{
    //ctor
}

level::~level()
{
    //dtor
}

std::vector<sf::RectangleShape> level::get_pieces(){
    return pieces;
}

std::vector<sf::FloatRect> level::get_collisions(){
    return collisions;
}

std::vector<sf::FloatRect> level::get_food_collisions(){
    return food_collisions;
}

std::vector<sf::Vector2f> level::get_power_pellets(){
    return power_pellets;
}

void level::add_wall(float x, float y, float w, float h){
    sf::RectangleShape piece(sf::Vector2f(w, h));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(x, y));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());
}

void level::add_collision(float x, float y, float w, float h){
    collisions.insert(collisions.begin(), sf::FloatRect(x, y, w, h));
}

void level::add_food_free_zone(float x, float y, float w, float h){
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(x, y, w, h));
}

void level::add_power_pellet(float x, float y){
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(x, y));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(x, y, 25, 25));
}
