#include "actor.h"

#define DEBUG
#include "util.h"

Actor::Actor() 
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

void Actor::on_collision( Actor& actor)
{

}

void Actor::on_collision( Static_actor& actor)
{
    debug_print("collide\n");
}

sf::RectangleShape Actor::get_sprite() 
{
    return sprite;
}

void Actor::set_x(float x) {
    _x = x;
    update_sprite();
}

void Actor::set_y(float y) {
    _y = y;
    update_sprite();
}

void Actor::move_x(float x) {
    _x += x;
    update_sprite();
}

void Actor::move_y(float y) {
    _y += y;
    update_sprite();
}

void Actor::set_speed_x(float x)
{
    _speed_x = x;
}
void Actor::set_speed_y(float y)
{
    _speed_y = y;
}

void Actor::set_acceleration_x(float x)
{
    _acceleration_x = x;
}

void Actor::set_acceleration_y(float y)
{
    _acceleration_y = y;
}

void Actor::add_speed_x(float x)
{
    _speed_x += x;
}

void Actor::add_speed_y(float y)
{
    _speed_y += y;
}

void Actor::add_acceleration_x(float x)
{
    _acceleration_x += x;
}

void Actor::add_acceleration_y(float y)
{
    _acceleration_y += y;
}

int Actor::get_x()
{
    return _x;
}
int Actor::get_y()
{
    return _y;
}

float Actor::get_speed_x()
{
    return _speed_x;
}
float Actor::get_speed_y()
{
    return _speed_y;
}

float Actor::get_acceleration_x()
{
    return _acceleration_x;
}
float Actor::get_acceleration_y()
{
    return _acceleration_y;
}

sf::RectangleShape Actor::get_collision()
{
    return _collision_rectangle;
}

void Actor::update_sprite()
{
    sprite.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
}
