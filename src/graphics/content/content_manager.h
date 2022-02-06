#pragma once

#include <SFML/Graphics.hpp>

class content_manager {
public:
    enum texture_type {
        PLAYER_TEXTURE = 0,
        TEXTURE_TYPE_CONUT = 1
    };

    enum rect_type {
        RECT_TYPE_PLAYER,
        RECT_TYPE_COUNT
    };
    static void init();
    static sf::Texture& get_texture(enum texture_type type);
    static sf::IntRect& get_texture_rect(enum rect_type type);

    static sf::Texture textures[TEXTURE_TYPE_CONUT];
private:
    static sf::IntRect texture_rect[RECT_TYPE_COUNT];
};