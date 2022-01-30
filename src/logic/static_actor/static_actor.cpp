#include "static_actor.h"

Static_actor::Static_actor()
{
    _x = 150;
    _y = 120;

    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2f(10, 20)); // TODO: use define or constexpr
    //todo
    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setSize(sf::Vector2f(10, 20));
}

sf::RectangleShape Static_actor::get_collision()
{
    return _collision_rectangle;
}

sf::RectangleShape Static_actor::get_sprite()
{
    return sprite;
}
