#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>
#include <content_manager.h>

class Actor
{
public:
    Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision );
    sf::Sprite get_sprite();
    b2BodyDef get_body_def();
    void set_body( b2Body* body );
    void on_collision( Actor& actor );

protected:
    sf::Vector2f _position;
    sf::Sprite _sprite;

    b2Body* _body;
    b2BodyDef _body_def;
    b2PolygonShape _shape;
};