#pragma once

#include <memory>

#include "dynamic_actor.h"
#include "static_actor.h"
#include "player_actor.h"
#include "content_manager.h"

class World_generator
{
public:
    static World make_world( int seed );

    static std::shared_ptr<Player_actor> make_player( float x, float y );
    static std::shared_ptr<Static_actor> make_tile_box( float x, float y );
};

struct World
{
    std::shared_ptr<Actors_vector> dynamic_actors;
    std::shared_ptr<Static_actors_vector> static_actors;

    sf::Vector2f player_position;
};
