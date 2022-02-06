#include "actor.h"

Actor::Actor( float x, float y, sf::RectangleShape sprite, sf::RectangleShape collision )
: _x( x )
, _y ( y )
, _sprite( sprite )
, _collision_rectangle( collision )
{
    _sprite.setFillColor(sf::Color::Red);
    _sprite.setPosition(sf::Vector2f(_x, _y));
    _sprite.setSize(sf::Vector2f(50, 50)); 

    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setSize(sf::Vector2f(50, 50));
}

sf::RectangleShape Actor::get_sprite() 
{
    return _sprite;
}

sf::RectangleShape Actor::get_collision()
{
    return _collision_rectangle;
}