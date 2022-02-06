#pragma once

#include <SFML/Graphics.hpp>

class Actor
{
public:
    Actor( float x, float y, sf::Sprite sprite, sf::RectangleShape collision );
    sf::Sprite get_sprite();
    sf::RectangleShape get_collision();
    void on_collision( Actor& actor );
protected:
    float _x, _y;
    sf::Sprite _sprite;
    sf::RectangleShape _collision_rectangle;
};