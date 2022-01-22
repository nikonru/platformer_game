#pragma once

#include "static_actor.h"
#include "actor.h"
#include <memory>
#include <vector>

class Physics_manager
{
public:

    Physics_manager( std::shared_ptr<Actors_vector> actors, std::shared_ptr<Static_actors_vector> static_actors );

    void update();
    std::shared_ptr<Actors_vector> get_actors();
    std::shared_ptr<Static_actors_vector> get_static_actors();

private:
    std::shared_ptr<Actors_vector> _actors;
    std::shared_ptr<Static_actors_vector> _static_actors;
};
