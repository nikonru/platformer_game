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
    bool check_rectangle_collision( float a_x, float a_y, float a_width, float a_height, float b_x, float b_y, float b_width, float b_height  );
    bool check_collision( Actor& actor, Actor& static_actor );
    bool check_expected_collision_by_x( Actor& actor, Actor& static_actor, float delta_x  );
    bool check_expected_collision_by_y( Actor& actor, Actor& static_actor, float delta_y  );
};
