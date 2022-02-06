#include "content_manager.h"
#include <cassert>

#define PATH_TO_CONTENT "content/"

sf::Texture content_manager::textures[COUNT] = {};
sf::IntRect content_manager::texture_rect[COUNT] = {};

Texture_data content_manager::get_texture_data(enum type type) {
    Texture_data td = {
        .texture = textures[type],
        .rect = texture_rect[type] 
    };
    return td;
}

void content_manager::init() {
    assert(textures[PLAYER].loadFromFile(PATH_TO_CONTENT"texture/player.png"));
    texture_rect[PLAYER] = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(64,108));

    assert(textures[TILE_BOX].loadFromFile(PATH_TO_CONTENT"texture/texture.png"));
    texture_rect[TILE_BOX] = sf::IntRect(sf::Vector2i(128,128), sf::Vector2i(64,64));
}