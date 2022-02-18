#pragma once

#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

class Physic_body
{
public:
    Physic_body( sf::Vector2f& position, sf::FloatRect& collision );

    void init( b2World& world );

    sf::Vector2f get_position();

private:
    b2Body* _body;
    b2BodyDef _body_def;
    b2PolygonShape _shape;
    b2FixtureDef _fixtureDef;

    const float pixels_in_meter = 100;
    
private:
    float pixels_to_meters( float pixels );
    float meters_to_pixels( float meters );
};
