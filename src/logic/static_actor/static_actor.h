#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Static_actor
{
    //TODO Derive from common base class with with actor
public:
    Static_actor();

    float _x, _y;

    sf::RectangleShape get_collision();
    sf::RectangleShape get_sprite();

private:
    sf::RectangleShape _collision_rectangle;
    sf::RectangleShape sprite;
};

struct Static_actors_vector
{
    std::vector<std::shared_ptr<Static_actor>> vector;
};
