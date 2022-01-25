#pragma once

#include "static_actor.h"
#include "actor.h"
#include <memory>
#include <vector>

class Physics_manager
{
public:
    void update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors );
};
