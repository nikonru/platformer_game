#pragma once

#include "physics_manager.h"
#include "static_actor.h"
#include "actor.h"
#include "controller.h"
#include <memory>
#include <vector>

class logic_manager 
{
public:
    void update();
    std::vector<std::shared_ptr<actor>> get_actors();
    std::vector<std::shared_ptr<static_actor>> get_static_actors();

private:
    std::shared_ptr<physics_manager> _physics_manager;
    //std::vector<std::shared_ptr<controller>> _controllers;
    std::shared_ptr<controller> _player_controller;
    // std::shared_ptr<actor> _player_actor;
};
