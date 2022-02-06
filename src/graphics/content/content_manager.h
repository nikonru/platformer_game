#pragma once

#include <SFML/Graphics.hpp>

struct Texture_data {
    sf::Texture &texture;
    sf::IntRect rect;
};

class content_manager {
public:
    enum type {
        PLAYER = 0,
        TILE_BOX,
        COUNT = 1
    };

    static void init();

    Texture_data get_texture_data(enum type type);

private:
    static sf::Texture textures[COUNT];
    static sf::IntRect texture_rect[COUNT];
};