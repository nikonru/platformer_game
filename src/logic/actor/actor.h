#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "static_actor.h"

class Actor
{
    //TODO Derive from common base class with with static_actor
public:
    Actor();

    void on_collision( Actor& actor);
    void on_collision( Static_actor& actor);
    sf::RectangleShape get_sprite();
    
    void set_x(float x);
    void set_y(float y);

    void move_x(float x);
    void move_y(float y);

    void set_speed_x(float x);
    void set_speed_y(float y);

    void set_acceleration_x(float x);
    void set_acceleration_y(float y);

    void add_speed_y(float y);
    void add_speed_x(float x);

    void add_acceleration_x(float x);
    void add_acceleration_y(float y);

    int get_x();
    int get_y();

    float get_speed_x();
    float get_speed_y();

    float get_acceleration_x();
    float get_acceleration_y();

    sf::RectangleShape get_collision();

private:
    
    void update_sprite();

    float _x, _y;

    float _speed_x, _speed_y;
    float _acceleration_x, _acceleration_y;

    sf::RectangleShape sprite;

    sf::RectangleShape _collision_rectangle;
};

struct Actors_vector
{
    std::vector<std::shared_ptr<Actor>> vector;
};

