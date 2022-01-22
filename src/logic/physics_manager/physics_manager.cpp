#include "physics_manager.h"

Physics_manager::Physics_manager( std::shared_ptr<Actors_vector> actors, std::shared_ptr<Static_actors_vector> static_actors )
{
    _actors = actors;
    _static_actors = static_actors;
}

void Physics_manager::update()
{
    for( auto& actor: _actors->vector)
    {
        actor->_x += actor->_speed_x;
        actor->_y += actor->_speed_y;

        actor->_speed_x += actor->_acceleration_x;
        actor->_speed_y += actor->_acceleration_y; 
    }
    
    for( auto& static_actor: _static_actors->vector)
    {
        //todo
    }
}

std::shared_ptr<Actors_vector> Physics_manager::get_actors()
{
    return _actors;
}

std::shared_ptr<Static_actors_vector> Physics_manager::get_static_actors()
{
    return _static_actors;
}