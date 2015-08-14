#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iterator>
#include <sstream>
#include "include/pacman.h"
#include "include/character.h"
#include "include/level1.h"
#include "include/level2.h"
#include "include/pinky.h"
#include "include/blinky.h"
#include "include/inky.h"
#include "include/clyde.h"
#include "include/food.h"
#include "include/powerpellet.h"
#include "include/mainmenu.h"
#include "include/AnimatedSprite.h"
#include "include/Animation.h"

const float player_velocity = 6.25f;
const float sprite_width = 25;
const float window_width = 800;
const float window_height = 675;
const float level_width = 525;
const int max_levels = 2;

const int UP = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int LEFT = 3;

bool up = false;
bool down = false;
bool left = false;
bool right = false;

sf::Clock clock_up;
sf::Clock clock_down;
sf::Clock clock_left;
sf::Clock clock_right;

//0 - scatter, 7 - chase, 27 - scatter, 34 - chase, 54 - scatter, 59 - chase, 79 - scatter, 84 - chase
sf::Clock ghost_mode;

sf::Texture pactex;
sf::Sprite lives_spr;

sf::Sprite gate;
sf::Sprite food_spr;
sf::Sprite pp_sprite;

sf::Sound foodcollect;
sf::Sound death;
sf::SoundBuffer foodbuf;
sf::SoundBuffer deathbuf;

//std::vector<ghost> ghostvect;
pinky pink;
blinky blink;
inky ink;
clyde clyd;
std::vector<food> foods;
std::vector<powerpellet> pellets;
int num_eaten;

int lev_num = 1;
level lev1;

sf::Font score_font;
sf::Text score_text;

bool on_menu = true;
mainmenu mainmen;

int score;
int lives = 3;
int ghost_stage = 0;
int nom_multiplier = 1;

sf::Text lives_text;

int ghost_frame_skip = 0;

//patch for MinGW not recognizing to_string
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

void update_stage(){
    int i = ghost_mode.getElapsedTime().asSeconds();
    switch (ghost_stage){
        case 0:
            if (i > 7)
                ghost_stage++;
            break;
        case 1:
            if (i > 27)
                ghost_stage++;
            break;
        case 2:
            if (i > 34)
                ghost_stage++;
            break;
        case 3:
            if (i > 54)
                ghost_stage++;
            break;
        case 4:
            if (i > 59)
                ghost_stage++;
            break;
        case 5:
            if (i > 79)
                ghost_stage++;
            break;
        case 6:
            if (i > 84)
                ghost_stage++;
            break;
        default:
            break;
    }

}

bool collides_with_map(sf::FloatRect rect, level &l){
    for (unsigned i = 0; i < l.get_collisions().size(); i++){
       // std::cout << l.get_collisions
        if (rect.intersects(l.get_collisions().at(i)))
            return true;
    }
    return false;
}

bool no_food_zone(sf::FloatRect rec, level l){
    for (unsigned i = 0; i < l.get_food_collisions().size(); i++){
        if (rec.intersects(l.get_food_collisions().at(i))){
            return true;
        }
    }
    return false;
}


void death_reset(pacman &p){
    lives -= 1;
    p.set_position(250, 500);

    //for (unsigned i = 0; i < ghostvect.size(); i++){
    //    ghostvect.at(i).return_to_start();
    //}

    pink.return_to_start();
    blink.return_to_start();
    ink.return_to_start();
    clyd.return_to_start();
}


void load_foods(sf::Sprite s, level &l){


    for (int x = 0; x < 525; x += 25){
        for (int y = 25; y < 650; y += 25){
            if (!collides_with_map(sf::FloatRect(x, y, 24.9f, 24.9f), l) && !no_food_zone(sf::FloatRect(x, y, 24.9f, 24.9f), l)){
                s.setPosition(sf::Vector2f(x, y));
                foods.insert(foods.begin(), food(s, sf::FloatRect(x + 7, y + 7, 9, 9)));
            }
        }
    }
}

void check_food_collisions(pacman &p){
    sf::FloatRect p_col = p.get_collision_box();
    for (std::vector<food>::iterator i = foods.begin(); i != foods.end(); i++){
        if (p_col.intersects(i->get_collision_box())){
            foods.erase(i);
            score += 100;
            num_eaten++;
            foodcollect.play();
            //std::cout << score << std::endl;
            break;
        }
    }
}

void check_pellet_collisions(pacman &p){
    sf::FloatRect p_col = p.get_collision_box();
    for (std::vector<powerpellet>::iterator i = pellets.begin(); i != pellets.end(); i++){
        if (p_col.intersects(i->get_collision_box())){
            pellets.erase(i);
            score += 1000;
            /*for (std::vector<ghost>::iterator j = ghostvect.begin(); j != ghostvect.end(); j++){
                j->set_vulnerable();
            }*/
            pink.set_vulnerable();
            blink.set_vulnerable();
            ink.set_vulnerable();
            clyd.set_vulnerable();
            nom_multiplier = 1;
            foodcollect.play();
            //std::cout << score << std::endl;
            break;
        }
    }
}





void get_key_inputs(pacman &p){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        up = true;
        p.set_dir(0);
        clock_up.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        down = true;
        p.set_dir(1);
        clock_down.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        left = true;
        p.set_dir(3);
        clock_left.restart();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        right = true;
        p.set_dir(2);
        clock_right.restart();
    }
}

void check_if_change_dir(pacman &p){
    sf::FloatRect collision_rect = p.get_collision_box();
    if (up && clock_up.getElapsedTime().asMilliseconds() < 500) {
        sf::FloatRect check_rect(collision_rect.left, collision_rect.top - (player_velocity), collision_rect.width, collision_rect.height);
        if (!collides_with_map(check_rect, lev1)){
            p.set_xvel(0);
            p.set_yvel(-player_velocity);
            up = false;
        }
    } else
        up = false;

    if (down && clock_down.getElapsedTime().asMilliseconds() < 500) {
        sf::FloatRect check_rect(collision_rect.left, collision_rect.top + (player_velocity), collision_rect.width, collision_rect.height);
        if (!collides_with_map(check_rect, lev1)){
            p.set_xvel(0);
            p.set_yvel(player_velocity);
            down = false;
        }
    } else
        down = false;

    if (left && clock_left.getElapsedTime().asMilliseconds() < 500) {
        sf::FloatRect check_rect(collision_rect.left - (player_velocity), collision_rect.top, collision_rect.width, collision_rect.height);
        if (!collides_with_map(check_rect, lev1)){
            p.set_xvel(-player_velocity);
            p.set_yvel(0);
            left = false;
        }
    } else
        left = false;

    if (right && clock_right.getElapsedTime().asMilliseconds() < 500) {
        sf::FloatRect check_rect(collision_rect.left + (player_velocity), collision_rect.top, collision_rect.width, collision_rect.height);
        if (!collides_with_map(check_rect, lev1)){
            p.set_xvel(player_velocity);
            p.set_yvel(0);
            right = false;
        }
    } else
        right = false;
}

void draw_level(sf::RenderWindow &w, std::vector<sf::RectangleShape> v){
    for (unsigned i = 0; i < v.size(); i++){
        w.draw(v.at(i));
    }

    w.draw(gate);

    for (unsigned i = 0; i < foods.size(); i++){
        w.draw(foods.at(i).get_sprite());
    }

    for (unsigned i = 0; i < pellets.size(); i++){
        w.draw(pellets.at(i).get_sprite());
    }
}

void draw_hud(sf::RenderWindow &w){
    sf::RectangleShape background (sf::Vector2f(275, 675));
    background.setPosition(525, 0);
    background.setFillColor(sf::Color::Black);
    w.draw(background);


    score_text.setString("Score: " + patch::to_string(score));
    score_text.setPosition(600, 25);
    w.draw(score_text);

    w.draw(lives_text);
    for (int i = 0; i < lives; i++){
        lives_spr.setPosition(620 + (30 * i), 150);
        w.draw(lives_spr);
    }

}

void update_ghosts(sf::RenderWindow &w, level &l, pacman &p){
    //std::cout << "updating pinky" << std::endl;
    //for (unsigned i = 0; i < ghostvect.size(); i++){
      //  ghostvect.at(i).update(l, p);
        //std::cout << "updated ghost pnky" << std::endl;
     //   w.draw(ghostvect.at(i).get_sprite());
   // }

    int ghost_time = ghost_mode.getElapsedTime().asSeconds();

    pink.update(l, p, ghost_stage);
    w.draw(pink.get_sprite());

    blink.update(l, p, ghost_stage);
    w.draw(blink.get_sprite());

    ink.update(l, p, blink, ghost_stage);
    w.draw(ink.get_sprite());

    clyd.update(l, p, ghost_stage);
    w.draw(clyd.get_sprite());
}

void load_power_pellets(sf::Sprite pp, level &l){
    for (unsigned i = 0; i < l.get_power_pellets().size(); i++){
        pp.setPosition(l.get_power_pellets().at(i).x, l.get_power_pellets().at(i).y);
        pellets.insert(pellets.begin(), powerpellet(pp));
    }
}

void end_reset(pacman &p, level &l){
    lives = 3;
    score = 0;
    lev_num = 1;
    p = pacman(pactex);
    pink.return_to_start();
    pink.reset_vulnerability();
    //pink.set_can_leave(false);
    blink.return_to_start();
    blink.reset_vulnerability();
    //blink.set_can_leave(false);
    ink.return_to_start();
    ink.reset_vulnerability();
    ink.set_can_leave(false);
    clyd.return_to_start();
    clyd.reset_vulnerability();
    clyd.set_can_leave(false);
    foods.clear();
    pellets.clear();
    l = level1();
    load_foods(food_spr, l);
    load_power_pellets(pp_sprite, l);
    num_eaten = 0;
}

void check_ghost_collisions(pacman &p){
    sf::FloatRect p_col = p.get_collision_box();
//    for (std::vector<ghost>::iterator i = ghostvect.begin(); i != ghostvect.end(); i++){
//        if (p_col.intersects(i->get_collision_box())){
//            if (i->is_vulnerable()){
//                i->return_to_start();
//            }
//            else {
//                death_reset(p);
//            }
//            //std::cout << score << std::endl;
//            break;
//        }
//    }

    if (p_col.intersects(pink.get_collision_box())){
        if (pink.is_vulnerable()){
            pink.go_to_jail();
            score += 2000 * nom_multiplier;
            nom_multiplier++;
        } else {
            death.play();
            if (lives == 1){
                end_reset(p, lev1);
                on_menu = true;
            } else {
                death_reset(p);
            }
        }
    }

    if (p_col.intersects(blink.get_collision_box())){
        if (blink.is_vulnerable()){
            blink.go_to_jail();
            score += 2000 * nom_multiplier;
            nom_multiplier++;
        } else {
            death.play();
            if (lives == 1){
                end_reset(p, lev1);
                on_menu = true;
            } else {
                death_reset(p);
            }
        }
    }

    if (p_col.intersects(ink.get_collision_box())){
        if (ink.is_vulnerable()){
            ink.go_to_jail();
            score += 2000 * nom_multiplier;
            nom_multiplier++;
        } else {
            death.play();
            if (lives == 1){
                end_reset(p, lev1);
                on_menu = true;
            } else {
                death_reset(p);
            }
        }
    }

    if (p_col.intersects(clyd.get_collision_box())){
        if (clyd.is_vulnerable()){
            clyd.go_to_jail();
            score += 2000 * nom_multiplier;
            nom_multiplier++;
        } else {
            death.play();
            if (lives == 1){
                end_reset(p, lev1);
                on_menu = true;
            } else {
                death_reset(p);
            }
        }
    }
}

void update_player(pacman &p){


    p.update();
    //std::cout << p.get_xpos() << ", " << p.get_ypos() << std::endl;
    if (p.get_xpos() < -12.5){
        p.set_xpos(level_width - 12.5);
    }
    if (p.get_xpos() > level_width - 12.5){
        p.set_xpos(-12.5);
    }

    if (collides_with_map(p.get_collision_box(), lev1)){
        p.step_back();
        p.set_xvel(0);
        p.set_yvel(0);
    }

    check_ghost_collisions(p);
    check_food_collisions(p);
    check_pellet_collisions(p);
}

void release_ghosts(){
    if (num_eaten >= 30){
        ink.set_can_leave(true);
    }

    if (num_eaten >= 150){
        clyd.set_can_leave(true);
    }
}

void check_space_to_play(){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        on_menu = false;
        pink.reset_clocks();
        ink.reset_clocks();
        clyd.reset_clocks();
        blink.reset_clocks();
        ghost_mode.restart();
        ghost_stage = 0;
    }
}

void draw_menu(sf::RenderWindow &w, mainmenu &m){
    w.draw(m.getBackground());
    w.draw(m.getGhosts());
    w.draw(m.getSpace());
}

void increment_level(pacman &p, level &l){
    if (lev_num != max_levels){
        lev_num++;
        p.set_pos(250, 500);

        if (lev_num == 2){
            l = level2();
            load_foods(food_spr, l);
            load_power_pellets(pp_sprite, l);
            pink.return_to_start();
            pink.reset_vulnerability();
            blink.return_to_start();
            blink.reset_vulnerability();
            ink.return_to_start();
            ink.reset_vulnerability();
            ink.set_can_leave(false);
            clyd.return_to_start();
            clyd.reset_vulnerability();
            clyd.set_can_leave(false);
            ghost_stage = 0;
            ghost_mode.restart();
            p.set_xvel(0);
            p.set_yvel(0);
            num_eaten = 0;
        }
    } else {
        end_reset(p, l);
        on_menu = true;
        l = level1();
        load_foods(food_spr, l);
        load_power_pellets(pp_sprite, l);
        pink.return_to_start();
        blink.return_to_start();
        ink.return_to_start();
        ink.set_can_leave(false);
        clyd.return_to_start();
        clyd.set_can_leave(false);
        ghost_stage = 0;
        ghost_mode.restart();
        p.set_xvel(0);
        p.set_yvel(0);
    }
}

void check_if_win(pacman &p, level &l){
    if (foods.size() == 0 && pellets.size() == 0){
        increment_level(p, l);
    }
}

int main()
{
    //std::cout << "1" << std::endl;
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Mac-Pan");

    window.setFramerateLimit(24);

    //sf::Texture tex;
    if (!pactex.loadFromFile("img/pacmansprites.png")){
        std::cout << "Failed to load pacman" << std::endl;
        return -1;
    }


    sf::Texture lives_tex;
    if (!lives_tex.loadFromFile("img/pacmanclose.png")){
        std::cout << "Failed to load Pacman's closed sprite" << std::endl;
        return -1;
    }

    lives_spr = sf::Sprite(lives_tex);
    lives_spr.scale(.5f, .5f);

    sf::Texture g;
    if (!g.loadFromFile("img/gate.png")){
        std::cout << "Failed to load gate" << std::endl;
        return -1;
    }

    gate = sf::Sprite(g);
    gate.setPosition(sf::Vector2f(225, 275));

    //std::cout << "2" << std::endl;

    sf::Texture f;
    if (!f.loadFromFile("img/food.png")){
        std::cout << "Failed to load food" << std::endl;
        return -1;
    }

    sf::Texture pp;
    if (!pp.loadFromFile("img/apple.png")){
        std::cout << "Failed to load power pellet" << std::endl;
        return -1;
    }

    sf::Texture bg;
    if (!bg.loadFromFile("img/mainmenu.png")){
        std::cout << "Failed to load title background" << std::endl;
        return -1;
    }

    sf::Texture ga;
    if (!ga.loadFromFile("img/titlespriteanim.png")){
        std::cout <<"Failed to load title animation" << std::endl;
        return -1;
    }
    Animation gaa;
    gaa.setSpriteSheet(ga);
    gaa.addFrame(sf::IntRect(0, 0, 250, 50));
    gaa.addFrame(sf::IntRect(0, 50, 250, 50));
    gaa.addFrame(sf::IntRect(0, 100, 250, 50));
    gaa.addFrame(sf::IntRect(0, 150, 250, 50));

    //std::cout << "3" << std::endl;

    sf::Texture sa;
    if (!sa.loadFromFile("img/spaceanim.png")){
        std::cout << "Failed to load title space animation" << std::endl;
        return -1;
    }

    Animation saa;
    saa.setSpriteSheet(sa);

    saa.addFrame(sf::IntRect(0, 0, 540, 54));
    saa.addFrame(sf::IntRect(0, 54, 540, 54));

    mainmen = mainmenu(sf::Sprite(bg), saa, gaa);

    if (!score_font.loadFromFile("Square.ttf")){
        std::cout << "Failed to load font" << std::endl;
        return -1;
    }
    score_text.setFont(score_font);

    lives_text.setFont(score_font);
    lives_text.setString("Lives");
    lives_text.setPosition(625, 100);

    //std::cout << "4" << std::endl;

    //pacspr = sf::Sprite(tex);
    //pacspr.scale(0.5f, 0.5f);

    pacman player(pactex);

    lev1 = level1();



    pp_sprite = sf::Sprite(pp);

    load_power_pellets(pp_sprite, lev1);

    food_spr = sf::Sprite(f);
    load_foods(food_spr, lev1);

    if (!deathbuf.loadFromFile("img/pacmandying.wav")){
        std::cout << "Could not load pacman's death" << std::endl;
        return -1;
    }

    death.setBuffer(deathbuf);

    if (!foodbuf.loadFromFile("img/pacmancollect.wav")){
        std::cout << "Could not load pacman's nom" << std::endl;
        return -1;
    }

    foodcollect.setBuffer(foodbuf);

    sf::Texture spoop_texture;
    if (!spoop_texture.loadFromFile("img/spoop.png")){
        std::cout << "Failed to load spoop" << std::endl;
        return -1;
    }
    pink = pinky(sf::Sprite(spoop_texture));
    //std::cout << "5" << std::endl;
    blink = blinky(sf::Sprite(spoop_texture));
    ink = inky(sf::Sprite(spoop_texture));
    clyd = clyde(sf::Sprite(spoop_texture));

    //ghostvect.insert(ghostvect.begin(), pink);



    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }



        window.clear();

        if (on_menu){
            mainmen.update();
            draw_menu(window, mainmen);
            check_space_to_play();
        } else {
            draw_level(window, lev1.get_pieces());
            update_player(player);
            //std::cout << "updated player" << std::endl;
            window.draw(player.get_anspr());
            //std::cout << "drew player" << std::endl;
            //if (ghost_frame_skip % 5 != 0){
                update_ghosts(window, lev1, player);
            //}

            update_stage();
            //std::cout << "updated ghosts" << std::endl;
            get_key_inputs(player);
            //std::cout << "key inputs" << std::endl;
            check_if_change_dir(player);
            //std::cout << "checked directions" << std::endl;
            check_if_win(player, lev1);
            draw_hud(window);
            //std::cout << "drew hud" << std::endl;
            release_ghosts();

            ghost_frame_skip++;
        }

        window.display();
    }

    return 0;
}

