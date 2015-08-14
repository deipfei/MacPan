#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <SFML/Graphics.hpp>

class level
{
    public:
        level();
        virtual ~level();
        std::vector<sf::RectangleShape> get_pieces();
        std::vector<sf::FloatRect> get_collisions();
        std::vector<sf::FloatRect> get_food_collisions();
        std::vector<sf::Vector2f> get_power_pellets();
        void add_wall(float, float, float, float);
        void add_collision(float, float, float, float);
        void add_food_free_zone(float, float, float, float);
        void add_power_pellet(float, float);
    protected:
        std::vector<sf::RectangleShape> pieces;
        std::vector<sf::FloatRect> collisions;
        std::vector<sf::FloatRect> food_collisions;
        std::vector<sf::Vector2f> power_pellets;
    private:
};

#endif // LEVEL_H
