#include "actor.h"

Actor::Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision )
: _position( position )
, _body( collision )
{
    _sprite.setPosition( _position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
}

Actor::Actor( sf::Vector2f position, Texture_data sprite )
: _position( position )
, _body( sf::FloatRect( _position, sf::Vector2f( static_cast<float>( sprite.rect.width ), static_cast<float>( sprite.rect.height ) ) ) )
{
    _sprite.setPosition( _position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
}

sf::Sprite Actor::get_sprite() 
{
    return _sprite;
}

void Actor::init_physics( b2World& world )
{
    _body.init( world );
}