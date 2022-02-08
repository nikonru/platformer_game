#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "actor.h"
#include "static_actor.h"

class Dynamic_actor : public Actor
{
public:
    Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite, sf::FloatRect collision );
    Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite );

    void on_collision( Actor& actor );
    
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

    float get_x();
    float get_y();

    float get_speed_x();
    float get_speed_y();

    float get_acceleration_x();
    float get_acceleration_y();

    void update_position();

protected:
    
    void update_sprite();

    sf::Vector2f _speed;
    sf::Vector2f _acceleration;

    sf::Vector2f _collision_offset;
};

struct Actors_vector
{
    std::vector<std::shared_ptr<Dynamic_actor>> vector;
};

