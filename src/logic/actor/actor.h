#pragma once

#include "physic_body.h"

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <content_manager.h>

class Actor
{
public:
    Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision );
    Actor( sf::Vector2f position, Texture_data sprite );

    sf::Sprite get_sprite();

    void on_collision( Actor& actor );

    void init_physics( b2World& world );

protected:
    sf::Vector2f _position;
    sf::Sprite _sprite;

    Physic_body _body;
};