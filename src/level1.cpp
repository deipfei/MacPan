#include <SFML/Graphics.hpp>
#include "../include/level1.h"

level1::level1() : level()
{
    //Outer walls
    sf::RectangleShape piece(sf::Vector2f(524.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 0));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 199.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 25));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 225));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(100, 250));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 300));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 350));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(100, 375));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(99.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 425));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 199.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 450));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(524.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(0, 650));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 199.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(500, 25));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 225));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 250));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 300));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 350));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 375));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(124.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 425));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 199.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(500, 450));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper left left 3x3 square
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(50, 50));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper left right 3x3 square
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(150, 50));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper left 3.2 rectangle
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(50, 150));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper right right 3x3 square
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 50));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper right left 3x3 square
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(300, 50));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper right 3.2 rectangle
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 150));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Top middle spike
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 99.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(250, 25));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper left T
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 174.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(150, 150));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(49.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(175, 225));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper right T
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 174.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(350, 150));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(49.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(300, 225));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Upper middle fat T
    piece = sf::RectangleShape(sf::Vector2f(124.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(200, 150));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(250, 200));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //Ghost cage
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 99.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(200, 275));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 99.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(300, 275));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(74.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(225, 350));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //THIS IS WHERE THE GATE WOULD GO

    //Left 1x4
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 99.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(150, 350));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //right 1x4
    piece = sf::RectangleShape(sf::Vector2f(24.9f, 99.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(350, 350));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //bottom upper T
    piece = sf::RectangleShape(sf::Vector2f(124.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(200, 400));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(250, 450));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //bottom lower T
    piece = sf::RectangleShape(sf::Vector2f(124.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(200, 525));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(250, 575));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower left 3x1
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(150, 475));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower right 3x1
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(300, 475));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower left 2x2
    piece = sf::RectangleShape(sf::Vector2f(49.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(25, 525));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower right 2x2
    piece = sf::RectangleShape(sf::Vector2f(124.9f, 49.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(450, 525));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower left L
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(50, 475));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(100, 500));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower right L
    piece = sf::RectangleShape(sf::Vector2f(74.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 475));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(400, 500));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower left upside-down T
    piece = sf::RectangleShape(sf::Vector2f(174.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(50, 600));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(150, 525));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    //lower right upside-down T
    piece = sf::RectangleShape(sf::Vector2f(174.9f, 24.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(300, 600));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    piece = sf::RectangleShape(sf::Vector2f(24.9f, 74.9f));
    piece.setFillColor(sf::Color::Blue);
    piece.setPosition(sf::Vector2f(350, 525));
    pieces.insert(pieces.begin(), piece);
    collisions.insert(collisions.begin(), piece.getGlobalBounds());

    collisions.insert(collisions.begin(), sf::FloatRect(225.1f, 275.1f, 74.9f, 24.9f));
    collisions.insert(collisions.begin(), sf::FloatRect(225.1f, 300.1f, 74.9f, 49.9f));
    collisions.insert(collisions.begin(), sf::FloatRect(0, 250, 100, 50));
    collisions.insert(collisions.begin(), sf::FloatRect(0, 375, 100, 50));
    collisions.insert(collisions.begin(), sf::FloatRect(425, 250, 100, 50));
    collisions.insert(collisions.begin(), sf::FloatRect(425, 375, 100, 50));

    food_collisions.insert(food_collisions.begin(), sf::FloatRect(0, 325, 125, 25));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(400, 325, 125, 25));

    power_pellets.insert(power_pellets.begin(), sf::Vector2f(25, 75));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(475, 75));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(475, 500));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(25, 500));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(25, 75, 25, 25));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(475, 75, 25, 25));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(475, 500, 25, 25));
    food_collisions.insert(food_collisions.begin(), sf::FloatRect(25, 500, 25, 25));

}

level1::~level1()
{
    //dtor
}
