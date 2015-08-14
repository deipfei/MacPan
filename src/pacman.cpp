#include "../include/pacman.h"
#include "../include/character.h"
#include "../include/Animation.h"
#include "../include/AnimatedSprite.h"
#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>

Animation *currentanim;
sf::Texture text;
Animation upan;
Animation downan;
Animation leftan;
Animation rightan;
AnimatedSprite anspr;
sf::Clock frame_time;

pacman::pacman(sf::Texture spr)
{
    //ctor
    xpos = 250;
    ypos = 500;
    xvel = 0;
    yvel = 0;
    text = spr;
    upan.setSpriteSheet(text);
    upan.addFrame(sf::IntRect(0, 0, 25, 25));
    upan.addFrame(sf::IntRect(75, 0, 25, 25));
    downan.setSpriteSheet(text);
    downan.addFrame(sf::IntRect(0, 0, 25, 25));
    downan.addFrame(sf::IntRect(25, 0, 25, 25));
    leftan.setSpriteSheet(text);
    leftan.addFrame(sf::IntRect(0, 0, 25, 25));
    leftan.addFrame(sf::IntRect(100, 0, 25, 25));
    rightan.setSpriteSheet(text);
    rightan.addFrame(sf::IntRect(0, 0, 25, 25));
    rightan.addFrame(sf::IntRect(50, 0, 25, 25));
    currentanim = &leftan;

    anspr = AnimatedSprite(sf::seconds(.2f), false, true);
    anspr.setPosition(sf::Vector2f(xpos, ypos));
    //std::cout << "1 pacman" << std::endl;
    anspr.play(*currentanim);


    //sprite.setPosition(xpos, ypos);
    collision_box = sprite.getGlobalBounds();
    dir = 3;
}

pacman::~pacman()
{
    //dtor
}

void pacman::update(){
    xpos += xvel;
    ypos += yvel;
    sprite.setPosition(sf::Vector2f(xpos, ypos));
    anspr.setPosition(sf::Vector2f(xpos, ypos));
    collision_box = anspr.getGlobalBounds();
    anspr.update(frame_time.restart());
}

void pacman::set_xpos(float x){
    xpos = x;
}

void pacman::set_ypos(float y){
    ypos = y;
}

void pacman::set_xvel(float x){
    xvel = x;
}

void pacman::set_yvel(float y){
    yvel = y;
}

void pacman::set_dir(int i){
    dir = i;
    set_curr_anim(i);
}

void pacman::set_pos(float x, float y){
    xpos = x;
    ypos = y;
    sprite.setPosition(x, y);
    collision_box = sprite.getGlobalBounds();
}

int pacman::get_dir(){
    return dir;
}

Animation* pacman::get_curr_anim(){
    return currentanim;
}

void pacman::set_curr_anim(int d){
    if (d == 0){
        currentanim = &upan;
    } else if (d == 1){
        currentanim = &downan;
    } else if (d == 2){
        currentanim = &rightan;
    } else {
        currentanim = &leftan;
    }

    anspr.play(*currentanim);
}

AnimatedSprite pacman::get_anspr(){
    return anspr;
}
