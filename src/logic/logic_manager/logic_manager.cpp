#include "logic_manager.h"

Logic_manager::Logic_manager() 
{
    _last_time_update = std::time(nullptr);

    _actors = std::make_shared<Actors_vector>();
    _static_actors = std::make_shared<Static_actors_vector>();

    auto player = std::make_shared<Actor>();
    _player_controller.connect_to_actor( player );

    _actors->vector.push_back( player );
}

void Logic_manager::update()
{
    //TODO use std::chrono idk
    auto current_time = std::time(nullptr);
    if( current_time - _last_time_update > (1/600) )
    {
        _physics_manager.update( _actors, _static_actors );
        _last_time_update = current_time;
    }
    
}

std::shared_ptr<Actors_vector> Logic_manager::get_actors()
{
    return _actors;
}

std::shared_ptr<Static_actors_vector> Logic_manager::get_static_actors()
{
    return _static_actors;
}
