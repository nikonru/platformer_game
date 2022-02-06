#pragma once

#include <SFML/Graphics.hpp>

class Actor
{
public:
    Actor( float x, float y, sf::RectangleShape sprite, sf::RectangleShape collision );
    sf::RectangleShape get_sprite();
    sf::RectangleShape get_collision();
    void on_collision( Actor& actor );
protected:
    float _x, _y;
    sf::RectangleShape _sprite;
    sf::RectangleShape _collision_rectangle;
};