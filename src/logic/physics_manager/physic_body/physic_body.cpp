#include "physic_body.h"

Physic_body::Physic_body( const sf::FloatRect& collision )
{
    _shape.SetAsBox( pixels_to_meters( collision.width/2 ), pixels_to_meters( collision.height/2 ) );
    _body_def.position.Set( pixels_to_meters( collision.left ), pixels_to_meters( collision.top ) );
}

void Physic_body::init( b2World& world )
{
    _body = world.CreateBody( &_body_def );
    
    if( _body_def.type == b2_dynamicBody )
    {
        _fixture_def.shape = &_shape;
        _fixture_def.density = 1.0f;
        _fixture_def.friction = 0.0f;

        _body->CreateFixture( &_fixture_def );
    }
    else
    {
       _body->CreateFixture( &_shape, 0.0f ); 
    }
}

void Physic_body::set_as_dynamic()
{
    _body_def.type = b2_dynamicBody;
}

sf::Vector2f Physic_body::get_position()
{
    auto body_position = _body->GetPosition();
    auto x = meters_to_pixels( body_position.x );
    auto y = meters_to_pixels( body_position.y );
    return sf::Vector2f( x, y );
}

sf::Vector2f Physic_body::get_velocity()
{
    auto body_velocity = _body->GetLinearVelocity();
    auto x = meters_to_pixels( body_velocity.x );
    auto y = meters_to_pixels( body_velocity.y );
    return sf::Vector2f( x, y );
}

void Physic_body::set_velocity( sf::Vector2f velocity )
{
    auto x = pixels_to_meters( velocity.x );
    auto y = pixels_to_meters( velocity.y );
    _body->SetLinearVelocity( b2Vec2( x, y ) );
}

void Physic_body::set_position( sf::Vector2f position )
{
    auto x = pixels_to_meters( position.x );
    auto y = pixels_to_meters( position.y );
    _body->SetTransform( b2Vec2( x, y ), 0 );
}

void Physic_body::kick( sf::Vector2f direction )
{
    auto x = pixels_to_meters( direction.x );
    auto y = pixels_to_meters( direction.y );
    _body->ApplyLinearImpulseToCenter( b2Vec2( x, y ), true );
}

float Physic_body::pixels_to_meters( float pixels )
{
    return pixels/pixels_in_meter;
}

float Physic_body::meters_to_pixels( float meters )
{
    return meters*pixels_in_meter;
}