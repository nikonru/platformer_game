#pragma once

#include <SFML/Graphics.hpp>

class Actor
{
public:
    sf::RectangleShape get_sprite();
    sf::RectangleShape get_collision();
    void on_collision( Actor& actor );
protected:
    float _x, _y;
    sf::RectangleShape sprite;
    sf::RectangleShape _collision_rectangle;
};