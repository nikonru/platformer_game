#pragma once

#include "static_actor.h"
#include "dynamic_actor.h"
#include <memory>
#include <vector>

class Physics_manager
{
public:
    void update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time );

private:
    bool check_collision( Dynamic_actor& actor, Static_actor& static_actor  );
};
