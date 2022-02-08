#include "world_generator.h"

using namespace std;

World World_generator::make_world( int seed )
{
    //TODO
}

std::shared_ptr<Player_actor> World_generator::make_player( float x, float y )
{
    auto player_sprite = Content_manager::get_texture_data( Content_manager::PLAYER );
    auto player_pos = sf::Vector2f( x, y );
    auto player_speed = sf::Vector2f( 0, 0 );
    sf::FloatRect player_collision;

    auto player = make_shared<Player_actor>( player_pos, player_speed, player_sprite, player_collision );

    return player;
}

std::shared_ptr<Static_actor> World_generator::make_tile_box( float x, float y )
{
    auto tile_box_sprite = Content_manager::get_texture_data(Content_manager::TILE_BOX);
    sf::FloatRect tile_block_collision;
    auto tile_block_pos = sf::Vector2f( 100, 120 );

    auto block = make_shared<Static_actor>( tile_block_pos, tile_box_sprite, tile_block_collision );

    return block;
}