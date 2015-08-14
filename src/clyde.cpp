#include "../include/clyde.h"
#include "../include/ghost.h"
#include <SFML/Graphics.hpp>
#include <cmath>

clyde::clyde() : ghost()
{
    //ctor
}

clyde::clyde(sf::Sprite s) : ghost(s)
{
    home_x = 0;
    home_y = 650;
    start_x = 225;
    start_y = 325;
    xpos = start_x;
    ypos = start_y;
    jail_x = start_x;
    jail_y = start_y;
    xvel = 0;
    yvel = 0;
    sprite.setColor(sf::Color(255, 165, 0));
    sprite.scale(.5f, .5f);
    jailed = true;
    col = sf::Color(255, 165, 0);
    can_leave = false;
    vuln_in_jail = false;
}

clyde::~clyde()
{
    //dtor
}

void clyde::update(level l, pacman p, int stage){
    //std::cout << "here's pnky's update" << std::endl;
    if (vulnerable){
        vulnerable_method();
    } else {
        sprite.setColor(col);
    }
    if (jailed && can_leave && !vuln_in_jail && gate_clock.getElapsedTime().asMilliseconds() > 1000){
        //std::cout << "jailed" << std::endl;
        leave_jail();
    } else if (!jailed){
        //x or y priority to prevent infinite turning/bounce loops
        int dir_priority = 0;
        if (std::abs(ypos - goal_y) > std::abs(xpos - goal_x)){
            dir_priority = 1;
        }

        if (stage == 0 || stage == 2 || stage == 4 || stage == 6){
            //std::cout << "scatter! pinky!" << std::endl;
            bool sel = false;
            if (search_for_intersection(l) && turn_timer.getElapsedTime().asMilliseconds() > 500){
                //std::cout << "found an intersection" << std::endl;
                dirs = find_options(l);
                //for (unsigned i = 0; i < dirs.size(); i++){
                   // std::cout << dirs.at(i) << std::endl;
                //}

                //x priority
                if (dir_priority == 0){
                    if (xpos >= home_x && !sel && dir != 2){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 3){
                                //std::cout << "selecting dir 3" << std::endl;
                                select_direction(3);
                                sel = true;
                            }
                        }
                    }

                    if (ypos <= home_y && !sel && dir != 0){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 1){
                                //std::cout << "selecting dir 1" << std::endl;
                                select_direction(1);
                                sel = true;
                            }
                        }
                    }

                    if (!sel){
                        select_direction(random_direction(dirs));
                    }
                }

                //y priority
                if (dir_priority == 1){
                    if (ypos <= home_y && !sel && dir != 0){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 1){
                                //std::cout << "selecting dir 1" << std::endl;
                                select_direction(1);
                                sel = true;
                            }
                        }
                    }

                    if (xpos >= home_x && !sel && dir != 2){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 3){
                                //std::cout << "selecting dir 3" << std::endl;
                                select_direction(3);
                                sel = true;
                            }
                        }
                    }
                }

                if (!sel){
                    select_direction(random_direction(dirs));
                }
            }

//            if (stage == 4 || stage == 6){
//                if (chase_pacman.getElapsedTime().asSeconds() >= 5){
//                    stage++;
//                    scatter.restart();
//                }
//            } else {
//                if (chase_pacman.getElapsedTime().asSeconds() >= 7){
//                    stage++;
//                    scatter.restart();
//                }
//            }
        }
        //chasing pacman
        else {
            //std::cout << "chase! pinky!" << std::endl;

            if (vulnerable){
                goal_x = home_x;
                goal_y = home_y;
            } else {
                float dist = std::sqrt(std::pow(ypos - p.get_ypos(), 2) + std::pow(xpos - p.get_xpos(), 2));

                if (dist > 200){
                    if (p.get_dir() == 0){
                        goal_x = p.get_xpos();
                        goal_y = p.get_ypos();
                    }
                    else if (p.get_dir() == 1){
                        goal_x = p.get_xpos();
                        goal_y = p.get_ypos();
                    }
                    else if (p.get_dir() == 2){
                        goal_x = p.get_xpos();
                        goal_y = p.get_ypos();
                    } else {
                        goal_x = p.get_xpos();
                        goal_y = p.get_ypos();
                    }
                } else {
                    goal_x = home_x;
                    goal_y = home_y;
                }
            }



            bool sel = false;
            if (search_for_intersection(l) && turn_timer.getElapsedTime().asMilliseconds() > 500){
                //std::cout << "found an intersection" << std::endl;
                dirs = find_options(l);
                //for (unsigned i = 0; i < dirs.size(); i++){
                    //std::cout << dirs.at(i) << std::endl;
                //}

                if (dir_priority == 0){
                    if (xpos >= goal_x && !sel && dir != 2){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 3){
                                //std::cout << "selecting dir 3" << std::endl;
                                select_direction(3);
                                sel = true;
                            }
                        }
                    }

                    else if (xpos < goal_x && !sel && dir != 3) {
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 2){
                                //std::cout << "selecting dir 2" << std::endl;
                                select_direction(2);
                                sel = true;
                            }
                        }
                    }

                    if (ypos >= goal_y && !sel && dir != 1){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 0){
                                //std::cout << "selecting dir 0" << std::endl;
                                select_direction(0);
                                sel = true;
                            }
                        }
                    }

                    else if (ypos < goal_y && !sel && dir != 0){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 1){
                                //std::cout << "selecting dir 1" << std::endl;
                                select_direction(1);
                                sel = true;
                            }
                        }
                    }
                }

                if (dir_priority == 1){
                    if (ypos >= goal_y && !sel && dir != 1){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 0){
                                //std::cout << "selecting dir 0" << std::endl;
                                select_direction(0);
                                sel = true;
                            }
                        }
                    }

                    else if (ypos < goal_y && !sel && dir != 0){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 1){
                                //std::cout << "selecting dir 1" << std::endl;
                                select_direction(1);
                                sel = true;
                            }
                        }
                    }

                    if (xpos >= goal_x && !sel && dir != 2){
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 3){
                                //std::cout << "selecting dir 3" << std::endl;
                                select_direction(3);
                                sel = true;
                            }
                        }
                    }

                    else if (xpos < goal_x && !sel && dir != 3) {
                        for (unsigned i = 0; i < dirs.size(); i++){
                            if (dirs.at(i) == 2){
                                //std::cout << "selecting dir 2" << std::endl;
                                select_direction(2);
                                sel = true;
                            }
                        }
                    }
                }

                if (!sel){
                    select_direction(random_direction(dirs));
                }
            }


//            if (stage == 1 || stage == 3 || stage == 5){
//                if (scatter.getElapsedTime().asSeconds() >= 20){
//                    stage++;
//                    chase_pacman.restart();
//                }
//            }
        }

    }

    update_position(l);
}
