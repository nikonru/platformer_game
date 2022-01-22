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
    std::vector<std::shared_ptr<Actor>> get_actors();
    std::vector<std::shared_ptr<Static_actor>> get_static_actors();

private:
    std::shared_ptr<Physics_manager> _physics_manager;
    std::vector<std::shared_ptr<Controller>> _controllers;
    std::shared_ptr<Controller> _player_controller;
    std::shared_ptr<Actor> _player_actor;
};
