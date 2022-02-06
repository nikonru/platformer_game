#pragma once

#include <SFML/Graphics.hpp>
#include <content_manager.h>


class Actor
{
public:
    Actor( float x, float y, Texture_data sprite, sf::FloatRect collision );
    sf::Sprite get_sprite();
    sf::FloatRect get_collision();
    void on_collision( Actor& actor );
protected:
    float _x, _y;
    sf::Sprite _sprite;
    sf::FloatRect _collision_rectangle;
};