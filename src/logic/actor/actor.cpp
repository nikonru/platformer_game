#include "actor.h"

Actor::Actor() 
{
    _x = 100;
    _y = 100;
    _speed_x = 1;

    _speed_y = _acceleration_x = _acceleration_y = 0;

    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2f(10, 20)); // TODO: use define or constexpr
    //todo
}

sf::RectangleShape Actor::get_sprite() 
{
    return sprite;
}

void Actor::set_x(int x) {
    _x = x;
    sprite.setPosition(sf::Vector2f(_x, _y));
}

void Actor::set_y(int y) {
    _y = y;
    sprite.setPosition(sf::Vector2f(_x, _y));
}
