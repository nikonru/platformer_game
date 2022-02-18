#include "physic_body.h"
#include <iostream>
Physic_body::Physic_body( sf::Vector2f& position, sf::FloatRect& collision )
{
    _shape.SetAsBox( pixels_to_meters( collision.width/2 ), pixels_to_meters( collision.top/2 ) );
    // std::cout<<position.x<<std::endl;
    // std::cout<<pixels_to_meters( collision.width/2 )<<std::endl;
    //_shape.SetAsBox( 1000,1000 );
    _body_def.position.Set( pixels_to_meters( position.x ), pixels_to_meters( position.y ) );
    _body_def.type = b2_dynamicBody;
}

void Physic_body::init( b2World& world )
{
    _body = world.CreateBody( &_body_def );
    
    _fixtureDef.shape = &_shape;
    _fixtureDef.density = 1.0f;
    _fixtureDef.friction = 0.3f;

    _body->CreateFixture( &_fixtureDef );
}

sf::Vector2f Physic_body::get_position()
{
    auto body_position = _body->GetPosition();
    auto x = meters_to_pixels( body_position.x );
    auto y = meters_to_pixels( body_position.y );
    return sf::Vector2f( x, y );
}

float Physic_body::pixels_to_meters( float pixels )
{
    return pixels/pixels_in_meter;
}

float Physic_body::meters_to_pixels( float meters )
{
    return meters*pixels_in_meter;
}