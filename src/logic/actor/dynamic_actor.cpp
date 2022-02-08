#include "dynamic_actor.h"
#include "content_manager.h"

#define DEBUG
#include "util.h"

using namespace std;

Dynamic_actor::Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite, sf::FloatRect collision )
: Actor( position, sprite, collision )
, _speed( speed )
, _acceleration( sf::Vector2f( 0, 0 ) )
{
    _collision_offset.x = _collision_rectangle.left - _position.x;
    _collision_offset.y = _collision_rectangle.top - _position.y;
}

Dynamic_actor::Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite )
: Actor( position, sprite )
, _speed( speed )
, _acceleration( sf::Vector2f( 0, 0 ) )
{}

void Dynamic_actor::on_collision( Actor& actor)
{
    debug_print("collide\n");
}

void Dynamic_actor::set_x( float x ) 
{
    _position.x = x;
    update_sprite();
}

void Dynamic_actor::set_y( float y ) 
{
    _position.y = y;
    update_sprite();
}

void Dynamic_actor::move_x(float x) 
{
    _position.x += x;
    update_sprite();
}

void Dynamic_actor::move_y(float y) {
    _position.y += y;
    update_sprite();
}

void Dynamic_actor::set_speed_x(float x)
{
    _speed.x = x;
}
void Dynamic_actor::set_speed_y(float y)
{
    _speed.y = y;
}

void Dynamic_actor::set_acceleration_x(float x)
{
    _acceleration.x = x;
}

void Dynamic_actor::set_acceleration_y(float y)
{
    _acceleration.y = y;
}

void Dynamic_actor::add_speed_x(float x)
{
    _speed.x += x;
}

void Dynamic_actor::add_speed_y(float y)
{
    _speed.y += y;
}

void Dynamic_actor::add_acceleration_x(float x)
{
    _acceleration.x += x;
}

void Dynamic_actor::add_acceleration_y(float y)
{
    _acceleration.y += y;
}

float Dynamic_actor::get_x()
{
    return _position.x;
}
float Dynamic_actor::get_y()
{
    return _position.y;
}

float Dynamic_actor::get_speed_x()
{
    return _speed.x;
}
float Dynamic_actor::get_speed_y()
{
    return _speed.y;
}

float Dynamic_actor::get_acceleration_x()
{
    return _acceleration.x;
}
float Dynamic_actor::get_acceleration_y()
{
    return _acceleration.y;
}

void Dynamic_actor::update_position()
{
    _sprite.setPosition( _body.get_position() );
}

void Dynamic_actor::update_sprite()
{
    _sprite.setPosition( _position );
    _collision_rectangle.left = _position.x + _collision_offset.x;
    _collision_rectangle.top = _position.y + _collision_offset.y;
}
