#include "dynamic_actor.h"
#include "content_manager.h"

#define DEBUG
#include "util.h"

using namespace std;

Dynamic_actor::Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite, sf::FloatRect collision )
: Actor( position, sprite, collision )
, _initial_speed( speed )
{
    _body.set_as_dynamic();
}

Dynamic_actor::Dynamic_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite )
: Actor( position, sprite )
, _initial_speed( speed )
{
    _body.set_as_dynamic();
}

void Dynamic_actor::on_collision( Actor& actor)
{
    debug_print("collide\n");
}

void Dynamic_actor::move( sf::Vector2f direction ) 
{
    _body.kick( direction );
}

void Dynamic_actor::set_velocity( sf::Vector2f velocity )
{
    _body.set_velocity( velocity );
}

sf::Vector2f Dynamic_actor::get_velocity()
{
    return _body.get_velocity();
}

void Dynamic_actor::init_physics( b2World& world )
{
    _body.init( world );
    _body.kick( _initial_speed );
}
