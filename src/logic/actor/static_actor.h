#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "actor.h"

class Static_actor : public Actor
{
public:
    Static_actor( sf::Vector2f position, Texture_data sprite, sf::FloatRect collision );
    Static_actor( sf::Vector2f position, Texture_data sprite );
};

struct Static_actors_vector
{
    std::vector<std::shared_ptr<Static_actor>> vector;
};
