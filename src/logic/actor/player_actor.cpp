#include "player_actor.h"

Player_actor::Player_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite, sf::FloatRect collision )
: Dynamic_actor( position, speed, sprite, collision )
{}

Player_actor::Player_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite )
: Dynamic_actor( position, speed, sprite )
{}

unsigned int Player_actor::get_hp()
{
    return _hp;
}