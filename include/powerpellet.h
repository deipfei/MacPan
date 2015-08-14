#ifndef POWERPELLET_H
#define POWERPELLET_H

#include <SFML/Graphics.hpp>


class powerpellet
{
    public:
        powerpellet(sf::Sprite);
        virtual ~powerpellet();
        sf::Sprite get_sprite();
        sf::FloatRect get_collision_box();
    protected:
        sf::Sprite sprite;
        sf::FloatRect collision_box;
    private:
};

#endif // POWERPELLET_H
