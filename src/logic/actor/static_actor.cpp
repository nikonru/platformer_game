#include "static_actor.h"

Static_actor::Static_actor()
{
    _x = 90;
    _y = 120;

    sprite.setFillColor(sf::Color::Red);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2f(100, 20)); // TODO: use define or constexpr
    //todo
    _collision_rectangle.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.setSize(sf::Vector2f(100, 20));
}
