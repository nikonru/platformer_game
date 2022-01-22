#include "actor.h"

Actor::Actor()
{
    
    //todo
}

sf::RectangleShape Actor::get_sprite() {
    sf::RectangleShape sprite;
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2f(10, 20)); // TODO: use define or constexpr

    return sprite;
}
