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

    void move_x(int x);
    void move_y(int y);

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

private:
    
    void update_sprite();

    int _x, _y;

    float _speed_x, _speed_y;
    float _acceleration_x, _acceleration_y;

    sf::RectangleShape sprite;

};

struct Actors_vector
{
    std::vector<std::shared_ptr<Actor>> vector;
};

