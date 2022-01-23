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
    
private:
    std::shared_ptr<Actors_vector> _actors;
    std::shared_ptr<Static_actors_vector> _static_actors;
};
