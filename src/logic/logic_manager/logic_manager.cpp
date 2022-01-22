#include "logic_manager.h"

logic_manager::logic_manager()
{
    std::vector<std::shared_ptr<actor>> actors;
    std::vector<std::shared_ptr<static_actor>> static_actors;
    
    std::shared_ptr<actor> player;
    _player_controller = std::make_shared<controller>( player );

    actors.push_back( player );

    _physics_manager = std::make_shared<physics_manager>( actors, static_actors);
}

void logic_manager::update()
{
    _physics_manager->update();
}

std::vector<std::shared_ptr<actor>> logic_manager::get_actors()
{
    return _physics_manager->get_actors();
}

std::vector<std::shared_ptr<static_actor>> logic_manager::get_static_actors()
{
    return _physics_manager->get_static_actors();
}