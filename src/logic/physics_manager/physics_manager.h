#pragma once

#include "static_actor.h"
#include "dynamic_actor.h"
#include "util.h"
#include <box2d/box2d.h>
#include <memory>
#include <vector>

class Physics_manager
{
public:
    Physics_manager();

    void update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time );

    void init_actors( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors );

    void debug_draw();

private:
    b2Vec2 _gravity = b2Vec2( 0, 3 );
    b2World _world{ _gravity };
    b2GLDraw _debug_render;
};
