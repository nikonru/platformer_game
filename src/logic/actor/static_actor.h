#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "actor.h"

class Static_actor : public Actor
{
public:
    Static_actor( float x, float y, sf::Sprite sprite, sf::RectangleShape collision );
};

struct Static_actors_vector
{
    std::vector<std::shared_ptr<Static_actor>> vector;
};
