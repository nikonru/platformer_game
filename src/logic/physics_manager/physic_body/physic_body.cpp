#include "physic_body.h"

Physic_body::Physic_body( sf::Vector2f position, sf::FloatRect collision )
{
    //_shape.SetAsBox( collision.width/2, collision.top/2 );
    _shape.SetAsBox( 1,1 );
    //_body_def.position.Set( _position.x, _position.y );
    _body_def.position.Set( 3,3 );
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
    return sf::Vector2f( body_position.x, body_position.y );
}