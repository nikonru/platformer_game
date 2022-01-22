#include "physics_manager.h"

Physics_manager::Physics_manager( std::vector<std::shared_ptr<Actor>> actors, std::vector<std::shared_ptr<Static_actor>> static_actors )
{
    _actors = actors;
    _static_actors = static_actors;
}

void Physics_manager::update()
{
    for( auto& actor: _actors)
    {
        actor->_x += actor->_speed_x;
        actor->_y += actor->_speed_y;

        actor->_speed_x += actor->_acceleration_x;
        actor->_speed_y += actor->_acceleration_y; 
    }
    
    for( auto& static_actor: _static_actors)
    {
        //todo
    }
}

std::vector<std::shared_ptr<Actor>> Physics_manager::get_actors()
{
    return _actors;
}

std::vector<std::shared_ptr<Static_actor>> Physics_manager::get_static_actors()
{
    return _static_actors;
}