#pragma once

#include "static_actor.h"
#include "dynamic_actor.h"
#include <box2d.h>
#include <memory>
#include <vector>

class Physics_manager
{
public:
    void update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time );

    void init_actors( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors );

private:
    b2Vec2 _gravity = b2Vec2( 0, -10 );
    b2World _world = b2World( _gravity );
};
