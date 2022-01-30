#include "dynamic_actor.h"

#define DEBUG
#include "util.h"

Dynamic_actor::Dynamic_actor() 
{
    _x = 100;
    _y = 100;
    _speed_x = 0;
    _acceleration_x = 0;
    _speed_y  = _acceleration_y = 0;

    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2f(10, 20)); // TODO: use define or constexpr
    //todo
    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setSize(sf::Vector2f(10, 20));
}

void Dynamic_actor::on_collision( Actor& actor)
{
    debug_print("collide\n");
}

void Dynamic_actor::set_x(float x) {
    _x = x;
    update_sprite();
}

void Dynamic_actor::set_y(float y) {
    _y = y;
    update_sprite();
}

void Dynamic_actor::move_x(float x) {
    _x += x;
    update_sprite();
}

void Dynamic_actor::move_y(float y) {
    _y += y;
    update_sprite();
}

void Dynamic_actor::set_speed_x(float x)
{
    _speed_x = x;
}
void Dynamic_actor::set_speed_y(float y)
{
    _speed_y = y;
}

void Dynamic_actor::set_acceleration_x(float x)
{
    _acceleration_x = x;
}

void Dynamic_actor::set_acceleration_y(float y)
{
    _acceleration_y = y;
}

void Dynamic_actor::add_speed_x(float x)
{
    _speed_x += x;
}

void Dynamic_actor::add_speed_y(float y)
{
    _speed_y += y;
}

void Dynamic_actor::add_acceleration_x(float x)
{
    _acceleration_x += x;
}

void Dynamic_actor::add_acceleration_y(float y)
{
    _acceleration_y += y;
}

int Dynamic_actor::get_x()
{
    return _x;
}
int Dynamic_actor::get_y()
{
    return _y;
}

float Dynamic_actor::get_speed_x()
{
    return _speed_x;
}
float Dynamic_actor::get_speed_y()
{
    return _speed_y;
}

float Dynamic_actor::get_acceleration_x()
{
    return _acceleration_x;
}
float Dynamic_actor::get_acceleration_y()
{
    return _acceleration_y;
}

void Dynamic_actor::update_sprite()
{
    sprite.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
}
