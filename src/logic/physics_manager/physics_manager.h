#pragma once

#include "static_actor.h"
#include "actor.h"
#include <memory>
#include <vector>

class Physics_manager
{
public:

    Physics_manager( std::vector<std::shared_ptr<Actor>> actors, std::vector<std::shared_ptr<Static_actor>> static_actors );

    void update();
    std::vector<std::shared_ptr<Actor>> get_actors();
    std::vector<std::shared_ptr<Static_actor>> get_static_actors();

private:
    std::vector<std::shared_ptr<Actor>> _actors;
    std::vector<std::shared_ptr<Static_actor>> _static_actors;
};
