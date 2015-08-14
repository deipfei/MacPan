#include "../include/mainmenu.h"
#include "../include/Animation.h"
#include "../include/AnimatedSprite.h"

mainmenu::mainmenu()
{
    //ctor
}

mainmenu::mainmenu(sf::Sprite bg, Animation s, Animation g)
{
    background = bg;

    spaceanim = s;
    ghostsanim = g;

    space = AnimatedSprite(sf::seconds(1), false, false);
    ghosts = AnimatedSprite(sf::seconds(1), false, false);

    space.setPosition(130, 500);
    ghosts.setPosition(275, 290);

    space.play(s);
    ghosts.play(g);

}

mainmenu::~mainmenu()
{
    //dtor
}

void mainmenu::update(){
    sf::Time t = frame_time.restart();
    ghosts.update(t);
    space.update(t);
}

AnimatedSprite mainmenu::getGhosts(){
    return ghosts;
}

AnimatedSprite mainmenu::getSpace(){
    return space;
}

sf::Sprite mainmenu::getBackground(){
    return background;
}
