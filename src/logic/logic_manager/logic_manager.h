#pragma once

#include <memory>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>

#include "physics_manager.h"
#include "static_actor.h"
#include "actor.h"
#include "controller.h"

class Logic_manager 
{
public:
    Logic_manager();
    void update();
    std::shared_ptr<Actors_vector> get_actors();
    std::shared_ptr<Static_actors_vector> get_static_actors();

private:
    Physics_manager _physics_manager;
    sf::Clock _clock;

    std::vector<std::shared_ptr<Controller>> _controllers;
    Controller _player_controller;
    std::shared_ptr<Actor> _player_actor;
    
    std::shared_ptr<Actors_vector> _actors;
    std::shared_ptr<Static_actors_vector> _static_actors;

    int64_t _last_time_update_us;
};
