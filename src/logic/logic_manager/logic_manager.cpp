#include "logic_manager.h"

Logic_manager::Logic_manager()
{
    std::shared_ptr<Actors_vector> actors;
    std::shared_ptr<Static_actors_vector> static_actors;
    
    std::shared_ptr<Actor> player;
    _player_controller = std::make_shared<Controller>( player );

    actors->vector.push_back( player );

    _physics_manager = std::make_shared<Physics_manager>( actors, static_actors);
}

void Logic_manager::update()
{
    _physics_manager->update();
}

std::shared_ptr<Actors_vector> Logic_manager::get_actors()
{
    return _physics_manager->get_actors();
}

std::shared_ptr<Static_actors_vector> Logic_manager::get_static_actors()
{
    return _physics_manager->get_static_actors();
}
