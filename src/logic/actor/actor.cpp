#include "actor.h"

Actor::Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision )
: _position( position )
{
    _sprite.setPosition( _position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
     
    _shape.SetAsBox( collision.width/2, collision.top/2 );
    _body_def.position.Set( _position.x, _position.y );
    _body->CreateFixture( &_shape, 0 );
}

sf::Sprite Actor::get_sprite() 
{
    return _sprite;
}

b2BodyDef Actor::get_body_def()
{
    return _body_def;
}

void Actor::set_body( b2Body* body )
{
    _body = body;
}