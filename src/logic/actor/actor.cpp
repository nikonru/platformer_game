#include "actor.h"

Actor::Actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision )
: _body( collision )
{
    _sprite.setPosition( position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
}

Actor::Actor( sf::Vector2f position, Texture_data sprite )
: _body( sf::FloatRect( position, sf::Vector2f( static_cast<float>( sprite.rect.width ), static_cast<float>( sprite.rect.height ) ) ) )
{
    _sprite.setPosition( position );

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
}

sf::Sprite Actor::get_sprite() 
{
    return _sprite;
}

void Actor::set_position( sf::Vector2f position )
{
    _body.set_position( position );
}

sf::Vector2f Actor::get_position()
{
    return _body.get_position();
}

void Actor::update_sprite()
{
    _sprite.setPosition( _body.get_position() );
}

void Actor::init_physics( b2World& world )
{
    _body.init( world );
}