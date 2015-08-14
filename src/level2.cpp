#include "../include/level2.h"
#include <SFML/Graphics.hpp>

level2::level2() : level()
{
    add_wall(0, 0, 524.9f, 24.9f);
    add_wall(0, 50, 24.9f, 574.9f);
    add_wall(500, 50, 24.9f, 574.9f);
    add_wall(0, 650, 524.9f, 24.9f);

    add_wall(25, 50, 24.9f, 99.9f);
    add_wall(475, 50, 24.9f, 99.9f);

    add_wall(75, 50, 49.9f, 99.9f);
    add_wall(400, 50, 49.9f, 99.9f);

    add_wall(150, 25, 224.9f, 24.9f);
    add_wall(150, 50, 49.9f, 24.9f);
    add_wall(325, 50, 49.9f, 24.9f);

    add_wall(225, 75, 74.9f, 24.9f);
    add_wall(200, 100, 124.9f, 24.9f);

    add_wall(200, 225, 124.9f, 24.9f);

    add_wall(250, 175, 24.9f, 24.9f);

    add_wall(200, 175, 24.9f, 49.9f);
    add_wall(300, 175, 24.9f, 49.9f);

    add_wall(200, 125, 124.9f, 24.9f);

    add_wall(150, 100, 24.9f, 74.9f);
    add_wall(350, 100, 24.9f, 74.9f);

    add_wall(50, 175, 24.9f, 124.9f);
    add_wall(450, 175, 24.9f, 124.9f);
    add_wall(75, 225, 74.9f, 24.9f);
    add_wall(375, 225, 74.9f, 24.9f);
    add_wall(150, 200, 24.9f, 74.9f);
    add_wall(350, 200, 24.9f, 74.9f);

    add_wall(100, 175, 24.9f, 24.9f);
    add_wall(400, 175, 24.9f, 24.9f);

    add_wall(100, 275, 24.9f, 124.9f);
    add_wall(400, 275, 24.9f, 124.9f);

    add_wall(125, 300, 24.9f, 24.9f);
    add_wall(375, 300, 24.9f, 24.9f);
    add_wall(75, 325, 24.9f, 24.9f);
    add_wall(425, 325, 24.9f, 24.9f);

    add_wall(25, 325, 24.9f, 24.9f);
    add_wall(475, 325, 24.9f, 24.9f);

    add_wall(175, 300, 24.9f, 24.9f);
    add_wall(325, 300, 24.9f, 24.9f);

    add_wall(200, 275, 24.9f, 99.9f);
    add_wall(300, 275, 24.9f, 99.9f);
    add_wall(225, 350, 74.9f, 24.9f);

    add_wall(150, 350, 24.9f, 49.9f);
    add_wall(350, 350, 24.9f, 49.9f);

    add_wall(175, 400, 24.9f, 24.9f);
    add_wall(325, 400, 24.9f, 24.9f);

    add_wall(50, 375, 24.9f, 74.9f);
    add_wall(450, 375, 24.9f, 74.9f);

    add_wall(75, 425, 74.9f, 24.9f);
    add_wall(375, 425, 74.9f, 24.9f);

    add_wall(125, 450, 49.9f, 24.9f);
    add_wall(350, 450, 49.9f, 24.9f);

    add_wall(225, 400, 74.9f, 49.9f);
    add_wall(200, 450, 124.9f, 24.9f);

    add_wall(50, 475, 49.9f, 74.9f);
    add_wall(425, 475, 49.9f, 74.9f);

    add_wall(75, 550, 49.9f, 24.9f);
    add_wall(400, 550, 49.9f, 24.9f);

    add_wall(100, 575, 24.9f, 24.9f);
    add_wall(400, 575, 24.9f, 24.9f);

    add_wall(25, 575, 24.9f, 24.9f);
    add_wall(475, 575, 24.9f, 24.9f);
    add_wall(25, 600, 49.9f, 24.9f);
    add_wall(450, 600, 49.9f, 24.9f);

    add_wall(125, 500, 74.9f, 24.9f);
    add_wall(150, 525, 49.9f, 24.9f);
    add_wall(325, 500, 74.9f, 24.9f);
    add_wall(325, 525, 49.9f, 24.9f);

    add_wall(225, 500, 24.9f, 49.9f);
    add_wall(275, 500, 24.9f, 49.9f);

    add_wall(150, 575, 49.9f, 24.9f);
    add_wall(325, 575, 49.9f, 24.9f);
    add_wall(225, 575, 74.9f, 49.9f);

    add_wall(100, 625, 99.9f, 24.9f);
    add_wall(325, 625, 99.9f, 24.9f);

    add_collision(225.1f, 275.1f, 74.9f, 24.9f);
    add_food_free_zone(175, 250, 174.9f, 149.9f);

    power_pellets.insert(power_pellets.begin(), sf::Vector2f(50, 575));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(450, 575));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(100, 200));
    power_pellets.insert(power_pellets.begin(), sf::Vector2f(400, 200));
}

level2::~level2()
{
    //dtor
}
