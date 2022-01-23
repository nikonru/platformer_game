#include "logic_manager.h"

Logic_manager::Logic_manager()
{
    _last_time_update = std::time(nullptr);

    auto actors = std::make_shared<Actors_vector>();
    auto static_actors = std::make_shared<Static_actors_vector>();
    
    auto player = std::make_shared<Actor>();
    _player_controller = std::make_shared<Controller>( player );

    actors->vector.push_back( player );

    _actors = actors;
    _static_actors = static_actors;

    _physics_manager = std::make_shared<Physics_manager>( _actors, _static_actors);
}

void Logic_manager::update()
{
    //TODO use std::chrono idk
    auto current_time = std::time(nullptr);
    if( current_time - _last_time_update > (1/600) )
    {
        _physics_manager->update();
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
