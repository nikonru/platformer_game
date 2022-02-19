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

    void set_position( sf::Vector2f position );
    sf::Vector2f get_position();

    void on_collision( Actor& actor );
    
    void update_sprite();

    void init_physics( b2World& world );

protected:
    sf::Sprite _sprite;

    Physic_body _body;
};