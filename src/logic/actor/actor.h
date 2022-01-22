#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Actor
{
public:
    Actor();

    void on_collision();
    sf::RectangleShape get_sprite();

    int _x, _y;

    float _speed_x, _speed_y;
    float _acceleration_x, _acceleration_y;
private:
};

