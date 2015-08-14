#ifndef GHOST_H
#define GHOST_H

#include "../include/character.h"
#include "../include/level.h"
#include "../include/pacman.h"
#include <vector>
#include <SFML/Graphics.hpp>


class ghost : public character
{
    public:
        ghost();
        ghost(sf::Sprite);
        virtual ~ghost();
        void make_decision();
        bool search_for_intersection(level);
        void leave_jail();
        //virtual void update(level, pacman);
        void update_position(level);
        void reset_vulnerability();
        std::vector<int> find_options(level);
        void select_direction(int);
        bool collides_with_map(level);
        void return_to_start();
        void go_to_jail();
        void set_vulnerable();
        bool is_vulnerable();
        void vulnerable_method();
        int random_direction(std::vector<int>);
        void set_can_leave(bool);
        void reset_clocks();
        //void update_stage(int);
    protected:
        sf::Clock gate_clock;
        sf::Clock turn_timer;
        sf::Clock vulnerability;
        bool jailed;
        float ghostvel;
        float start_x;
        float start_y;
        float jail_x;
        float jail_y;
        int home_x;
        int home_y;
        bool vulnerable;
        bool vuln_in_jail;
        sf::Color col;
        float goal_x;
        float goal_y;
        int dir;
        std::vector<int> dirs;
        bool can_leave;
    private:
};

#endif // GHOST_H
