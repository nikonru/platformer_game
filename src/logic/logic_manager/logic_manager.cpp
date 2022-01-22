#include "logic_manager.h"

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