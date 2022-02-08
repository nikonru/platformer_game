#include "actor.h"

Actor::Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision )
: _position( position )
, _body( _position, collision )
{
    _sprite.setPosition( _position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
}

Actor::Actor( sf::Vector2f position, Texture_data sprite )
: _position( position )
{
    _sprite.setPosition( _position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
     
    _collision_rectangle.left = _position.x;
    _collision_rectangle.top = _position.y;
    _collision_rectangle.width = static_cast<float>( sprite.rect.width );
    _collision_rectangle.height = static_cast<float>( sprite.rect.height );
}

sf::Sprite Actor::get_sprite() 
{
    return _sprite;
}

void Actor::init_physics( b2World& world )
{
    _body.init( world );
}