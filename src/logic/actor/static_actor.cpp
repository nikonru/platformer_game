#include "static_actor.h"

Static_actor::Static_actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision )
: Actor( position, sprite, collision )
{}

Static_actor::Static_actor( sf::Vector2f position, Texture_data sprite )
: Actor( position, sprite )
{}
