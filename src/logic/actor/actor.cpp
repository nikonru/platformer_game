#include "actor.h"

sf::RectangleShape Actor::get_sprite() 
{
    return sprite;
}

sf::RectangleShape Actor::get_collision()
{
    return _collision_rectangle;
}