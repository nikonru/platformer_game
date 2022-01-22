#include "physics_manager.h"

void physics_manager::update()
{
    for( auto& actor: _actors)
    {
        actor->_x += actor->_speed_x
        actor->_y += actor->_speed_y

        actor->_speed_x += actor->_acceleration_x;
        actor->_speed_y += actor->_acceleration_y; 
    }

    
    for( auto& static_actor: _static_actors)
    {
        //todo
    }
}

std::vector<std::shared_ptr<actor>> physics_manager::get_actors()
{
    return _actors;
}

std::vector<std::shared_ptr<static_actor>> physics_manager::get_static_actors()
{
    return static_actors;
}