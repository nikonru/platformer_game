#pragma once

#include <array>
#include <SFML/Graphics.hpp>

struct Texture_data {
    sf::Texture &texture;
    sf::IntRect rect;
};

class Content_manager {
public:
    enum type {
        PLAYER = 0,
        TILE_BOX,
        COUNT
    };

    static void init();

    static Texture_data get_texture_data(enum type type);

private:
    static std::array<sf::Texture, COUNT> textures;
    static std::array<sf::IntRect, COUNT> texture_rect;
};