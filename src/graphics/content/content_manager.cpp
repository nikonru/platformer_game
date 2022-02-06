#include "content_manager.h"
#include <cassert>

#define PATH_TO_CONTENT "content/"

sf::Texture content_manager::textures[TEXTURE_TYPE_CONUT] = {};
sf::IntRect content_manager::texture_rect[RECT_TYPE_COUNT] = {};

void content_manager::init() {
    assert(textures[PLAYER_TEXTURE].loadFromFile(PATH_TO_CONTENT"texture/player.png"));
    texture_rect[RECT_TYPE_PLAYER] = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(64,108));
}

sf::Texture& content_manager::get_texture(enum texture_type type) {
    return content_manager::textures[type];
}

sf::IntRect& content_manager::get_texture_rect(enum rect_type type) {
    return content_manager::texture_rect[type];
}