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

    void move( sf::Vector2f direction );
    void set_velocity( sf::Vector2f velocity );

    sf::Vector2f get_velocity();

    void init_physics( b2World& world );

protected:

    sf::Vector2f _initial_speed;
};

struct Actors_vector
{
    std::vector<std::shared_ptr<Dynamic_actor>> vector;
};

