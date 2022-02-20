#include "world_generator.h"

using namespace std;

World World_generator::make_world( int seed )
{
    World world;
    world.dynamic_actors = make_shared<Actors_vector>();
    world.static_actors = make_shared<Static_actors_vector>();
    
    //TODO

    auto tile_block_1 = make_tile_box( 100, 120 ); 
    auto tile_block_2 = make_tile_box( 300, 120 ); 
    world.static_actors->vector.push_back( tile_block_1 );
    world.static_actors->vector.push_back( tile_block_2 );

    world.player_position = sf::Vector2f( 0, 0 );

    return world;
}

std::shared_ptr<Player_actor> World_generator::make_player( sf::Vector2f position )
{
    auto player_sprite = Content_manager::get_texture_data( Content_manager::PLAYER );
    auto player_speed = sf::Vector2f( 0, 0 );
    // sf::FloatRect player_collision;

    // float x_offset = 17;

    // player_collision.left = position.x + x_offset; 
    // player_collision.top = position.y;
    // player_collision.width = static_cast<float>( player_sprite.rect.width - 2*x_offset );
    // player_collision.height = static_cast<float>( player_sprite.rect.height );

    auto player = make_shared<Player_actor>( position, player_speed, player_sprite );

    return player;
}

std::shared_ptr<Static_actor> World_generator::make_tile_box( sf::Vector2f position )
{
    auto tile_box_sprite = Content_manager::get_texture_data(Content_manager::TILE_BOX);

    auto block = make_shared<Static_actor>( position, tile_box_sprite );

    return block;
}

std::shared_ptr<Player_actor> World_generator::make_player( float x, float y )
{
    auto player = make_player( sf::Vector2f( x, y) );

    return player;
}

std::shared_ptr<Static_actor> World_generator::make_tile_box( float x, float y )
{
    auto block = make_tile_box( sf::Vector2f( x, y) );

    return block;
}