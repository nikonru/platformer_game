#pragma once

#include "physics_manager.h"
#include "static_actor.h"
#include "actor.h"
#include "controller.h"
#include <memory>
#include <vector>

class Logic_manager 
{
public:
    Logic_manager();
    void update();
    std::shared_ptr<Actors_vector> get_actors();
    std::shared_ptr<Static_actors_vector> get_static_actors();

private:
    std::shared_ptr<Physics_manager> _physics_manager;
    std::vector<std::shared_ptr<Controller>> _controllers;
    std::shared_ptr<Controller> _player_controller;
    std::shared_ptr<Actor> _player_actor;
};
