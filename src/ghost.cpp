#include "../include/ghost.h"
#include "../include/character.h"
#include <vector>
#include <iostream>
#include <typeinfo>

ghost::ghost(){
}

ghost::ghost(sf::Sprite s)
{
    sprite = s;
    jailed = true;
    xvel = 0;
    yvel = 0;
    ghostvel = 5;
    vulnerable = false;
    dir = 0;
    can_leave = false;
    vuln_in_jail = false;
}

ghost::~ghost()
{
    //dtor
}

void ghost::leave_jail(){
    if (xpos < 250){
        xvel = ghostvel;
        yvel = 0;
    } else if (xpos > 250){
        xvel = -ghostvel;
        yvel = 0;
    } else if (ypos < 250){
        yvel = ghostvel;
        xvel = 0;
    } else if (ypos > 250){
        yvel = -ghostvel;
        xvel = 0;
    } else {
        jailed = false;
        dir = 0;
    }
}

void ghost::update_position(level l){
    xpos += xvel;
    ypos += yvel;
    while (collides_with_map(l)){
        step_back();
        //std::cout << "colliding" << std::endl;
        //std::cout << "vel " << xvel << " " << yvel << std::endl;
        //std::cout << "pos " << xpos << " " << ypos << std::endl;
    }

    if (xpos < -10){
        xpos = 515;
        turn_timer.restart();
    }
    if (xpos > 515){
        //std::cout << xpos << std::endl;
        xpos = -10;
        turn_timer.restart();
    }

    sprite.setPosition(xpos, ypos);
    collision_box = sprite.getGlobalBounds();
}

void ghost::reset_vulnerability(){
    vulnerable = false;
    vuln_in_jail = false;
}

//search areas perpendicular to direction of travel for places to change direction
bool ghost::search_for_intersection(level l){
    //std::cout << "searching" << std::endl;
    bool opening = false;
    bool curr = true;
    std::vector<sf::FloatRect> levelcol = l.get_collisions();
    if (xvel != 0){
        sf::FloatRect colcheck (collision_box.left, collision_box.top + (4 * ghostvel), collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        if (curr){
            return true;
        }

        curr = true;
        colcheck = sf::FloatRect(collision_box.left, collision_box.top - (4 * ghostvel), collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        return curr;
    } else if (yvel != 0){
        sf::FloatRect colcheck (collision_box.left + (4 * ghostvel), collision_box.top, collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        if (curr){
            return true;
        }

        curr = true;
        colcheck  = sf::FloatRect(collision_box.left - (4 * ghostvel), collision_box.top, collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        return curr;
    } else {
        sf::FloatRect colcheck (collision_box.left, collision_box.top + (4 * ghostvel), collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        if (curr){
            return true;
        }

        curr = true;
        colcheck  = sf::FloatRect(collision_box.left + (4 * ghostvel), collision_box.top, collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        if (curr){
            return true;
        }

        curr = true;
        colcheck  = sf::FloatRect(collision_box.left - (4 * ghostvel), collision_box.top, collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        if (curr){
            return true;
        }

        curr = true;
        colcheck  = sf::FloatRect(collision_box.left, collision_box.top - (4 * ghostvel), collision_box.width, collision_box.height);
        for (unsigned i = 0; i < levelcol.size(); i++){
            if (colcheck.intersects(levelcol.at(i))){
                curr = false;
                break;
            }
        }

        return curr;
    }

}

std::vector<int> ghost::find_options(level l){
    std::vector<int> options;
    bool curr = true;
    std::vector<sf::FloatRect> levelcol = l.get_collisions();
    sf::FloatRect colcheck  = sf::FloatRect(collision_box.left, collision_box.top + 10, collision_box.width, collision_box.height);
    for (unsigned i = 0; i < levelcol.size(); i++){
        if (colcheck.intersects(levelcol.at(i))){
            curr = false;
            //break;
        }
    }

    if (curr){
        options.insert(options.end(), 1);
    }
    curr = true;

    colcheck  = sf::FloatRect(collision_box.left + 10, collision_box.top, collision_box.width, collision_box.height);
    for (unsigned i = 0; i < levelcol.size(); i++){
        if (colcheck.intersects(levelcol.at(i))){
            curr = false;
            //break;
        }
    }

    if (curr){
        options.insert(options.end(), 2);
    }
    curr = true;

    colcheck  = sf::FloatRect(collision_box.left, collision_box.top - 10, collision_box.width, collision_box.height);
    for (unsigned i = 0; i < levelcol.size(); i++){
        if (colcheck.intersects(levelcol.at(i))){
            curr = false;
            //break;
        }
    }

    if (curr){
        options.insert(options.end(), 0);
    }
    curr = true;

    colcheck  = sf::FloatRect(collision_box.left - 10, collision_box.top, collision_box.width, collision_box.height);
    for (unsigned i = 0; i < levelcol.size(); i++){
        if (colcheck.intersects(levelcol.at(i))){
            curr = false;
            //break;
        }
    }

    if (curr){
        options.insert(options.end(), 3);
    }
    curr = true;

    return options;
}

void ghost::select_direction(int i){
    //std::cout << typeid(this).name() << "Choosing direction " << i << std::endl;
    if (i == 0){
        xvel = 0;
        yvel = -ghostvel;
        turn_timer.restart();
        dir = 0;
    } else if (i == 1){
        xvel = 0;
        yvel = ghostvel;
        turn_timer.restart();
        dir = 1;
    } else if (i == 2){
        xvel = ghostvel;
        yvel = 0;
        turn_timer.restart();
        dir = 2;
    } else if (i == 3){
        xvel = -ghostvel;
        yvel = 0;
        turn_timer.restart();
        dir = 3;
    }
}

bool ghost::collides_with_map(level l){
    sf::FloatRect rect = get_collision_box();
    for (unsigned i = 0; i < l.get_collisions().size(); i++){
       // std::cout << l.get_collisions
        sf::FloatRect temp = l.get_collisions().at(i);
        if (rect.intersects(temp)){
            if (jailed && ypos >= 250 && (temp.top == 275.1f || temp.top == 300.1f) && temp.left == 225.1f){
                continue;
            }
            return true;
        }
    }
    return false;
}

void ghost::return_to_start(){
    vulnerable = false;
    jailed = true;
    gate_clock.restart();
    xpos = start_x;
    ypos = start_y;
    xvel = 0;
    yvel = 0;
    sprite.setPosition(xpos, ypos);
    collision_box = sprite.getGlobalBounds();
    dir = 0;
}//

void ghost::go_to_jail(){
    jailed = true;
    gate_clock.restart();
    xpos = jail_x;
    ypos = jail_y;
    xvel = 0;
    yvel = 0;
    sprite.setPosition(xpos, ypos);
    collision_box = sprite.getGlobalBounds();
    dir = 0;
}


void ghost::set_vulnerable(){
    vulnerability.restart();
    vulnerable = true;
    vuln_in_jail = true;
}

bool ghost::is_vulnerable(){
    return vulnerable;
}

void ghost::vulnerable_method(){
    if (vulnerability.getElapsedTime().asSeconds() > 10){
        vulnerable = false;
        vuln_in_jail = false;
    }
    else if (vulnerability.getElapsedTime().asSeconds() > 9){
        sprite.setColor(sf::Color::White);
    }
    else
        sprite.setColor(sf::Color::Blue);
}

int ghost::random_direction(std::vector<int> dirs){
    int opp = 0;

    if (dir == 0)
        opp = 1;

    else if (dir == 2)
        opp = 3;

    else if (dir == 3)
        opp = 2;

    int i = rand() % dirs.size();

    while (dirs.at(i) == opp){
        i = rand() % dirs.size();
    }

    return dirs.at(i);
}

void ghost::set_can_leave(bool b){
    can_leave = b;
}

void ghost::reset_clocks(){
    gate_clock.restart();
}

