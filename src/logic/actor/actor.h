#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Actor
{
public:
    Actor();

    void on_collision();
    sf::RectangleShape get_sprite();
    
    void set_x(int x);
    void set_y(int y);

    int _x, _y;

    float _speed_x, _speed_y;
    float _acceleration_x, _acceleration_y;
private:
    sf::RectangleShape sprite;
};

struct Actors_vector
{
    std::vector<std::shared_ptr<Actor>> vector;
};

