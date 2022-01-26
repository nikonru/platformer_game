#include "logic_manager.h"

using namespace std;

Logic_manager::Logic_manager() 
{
    _last_time_update_us = 0;

    _actors = make_shared<Actors_vector>();
    _static_actors = make_shared<Static_actors_vector>();

    auto player = make_shared<Actor>();
    _player_controller.attach_to_actor( player );

    _actors->vector.push_back( player );

    _clock.start();
}

void Logic_manager::update()
{
    auto current_time = _clock.get_time();
    int64_t delta_time_us = current_time.asMicroseconds() - _last_time_update_us;

    _physics_manager.update( _actors, _static_actors, delta_time_us );
    _last_time_update_us = current_time.asMicroseconds();
}

shared_ptr<Actors_vector> Logic_manager::get_actors()
{
    return _actors;
}

shared_ptr<Static_actors_vector> Logic_manager::get_static_actors()
{
    return _static_actors;
}
