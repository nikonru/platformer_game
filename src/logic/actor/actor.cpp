#include "actor.h"

Actor::Actor()
{
    
    //todo
}

sf::RectangleShape actor::get_sprite() {
    sf::RectangleShape sprite;
    sprite.setFillColor(sf::Color::Green);
    sprite.setPosition(sf::Vector2f(_x, _y));
    sprite.setSize(sf::Vector2i(10, 20)); // TODO: use define or constexpr

    return sprite;
}
