#include "content_manager.h"
#include <cassert>

sf::Texture content_manager::textures[TEXTURE_TYPE_CONUT] = {};
sf::IntRect content_manager::texture_rect[RECT_TYPE_COUNT] = {};

void content_manager::init() {
    assert(textures[PLAYER_TEXTURE].loadFromFile("/home/slava/project/platformer_game/build/bin/player.png"));
    texture_rect[RECT_TYPE_PLAYER] = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(100,200));
}

sf::Texture& content_manager::get_texture(enum texture_type type) {
    return content_manager::textures[type];
}

sf::IntRect& content_manager::get_texture_rect(enum rect_type type) {
    return content_manager::texture_rect[type];
}