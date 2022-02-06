#include "actor.h"

Actor::Actor( float x, float y, Texture_data sprite, sf::FloatRect collision )
: _x( x )
, _y ( y )
, _collision_rectangle( collision )
{
    _sprite.setPosition(sf::Vector2f(_x, _y));

    _sprite.setTexture( sprite.texture );
    _sprite.setTextureRect( sprite.rect );
     
    _collision_rectangle.left = _x;
    _collision_rectangle.top = _y;
    _collision_rectangle.width = static_cast<float>( sprite.rect.width );
    _collision_rectangle.height = static_cast<float>( sprite.rect.height );
}

sf::Sprite Actor::get_sprite() 
{
    return _sprite;
}

sf::FloatRect Actor::get_collision()
{
    return _collision_rectangle;
}