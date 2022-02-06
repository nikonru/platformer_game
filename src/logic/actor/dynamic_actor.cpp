#include "dynamic_actor.h"
#include "content_manager.h"

#define DEBUG
#include "util.h"

Dynamic_actor::Dynamic_actor( float x, float y, float speed_x, float speed_y, Texture_data sprite, sf::FloatRect collision )
: Actor( x, y, sprite, collision )
, _speed_x( speed_x )
, _speed_y( speed_y )
, _acceleration_x( 0 )
, _acceleration_y( 0 )
{

    _sprite.setPosition(sf::Vector2f(_x, _y));
    //_sprite.setTexture(content_manager::get_texture(content_manager::PLAYER_TEXTURE));
    //_sprite.setTextureRect(content_manager::get_texture_rect(content_manager::RECT_TYPE_PLAYER));
    //_sprite.
    //_sprite.setScale(sf::Vector2f(10,10));
    //todo
}

void Dynamic_actor::on_collision( Actor& actor)
{
    debug_print("collide\n");
}

void Dynamic_actor::set_x( float x ) 
{
    _x = x;
    update_sprite();
}

void Dynamic_actor::set_y( float y ) 
{
    _y = y;
    update_sprite();
}

void Dynamic_actor::move_x(float x) 
{
    _x += x;
    update_sprite();
}

void Dynamic_actor::move_y(float y) {
    _y += y;
    update_sprite();
}

void Dynamic_actor::set_speed_x(float x)
{
    _speed_x = x;
}
void Dynamic_actor::set_speed_y(float y)
{
    _speed_y = y;
}

void Dynamic_actor::set_acceleration_x(float x)
{
    _acceleration_x = x;
}

void Dynamic_actor::set_acceleration_y(float y)
{
    _acceleration_y = y;
}

void Dynamic_actor::add_speed_x(float x)
{
    _speed_x += x;
}

void Dynamic_actor::add_speed_y(float y)
{
    _speed_y += y;
}

void Dynamic_actor::add_acceleration_x(float x)
{
    _acceleration_x += x;
}

void Dynamic_actor::add_acceleration_y(float y)
{
    _acceleration_y += y;
}

float Dynamic_actor::get_x()
{
    return _x;
}
float Dynamic_actor::get_y()
{
    return _y;
}

float Dynamic_actor::get_speed_x()
{
    return _speed_x;
}
float Dynamic_actor::get_speed_y()
{
    return _speed_y;
}

float Dynamic_actor::get_acceleration_x()
{
    return _acceleration_x;
}
float Dynamic_actor::get_acceleration_y()
{
    return _acceleration_y;
}

void Dynamic_actor::update_sprite()
{
    _sprite.setPosition(sf::Vector2f(_x, _y));
    _collision_rectangle.top = _y;
    _collision_rectangle.left = _x;
}
