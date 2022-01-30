#pragma once

#include <memory>
#include <vector>
#include <ctime>

#include "game_clock.h"

#include "physics_manager.h"
#include "static_actor.h"
#include "dynamic_actor.h"
#include "controller.h"
#include "input_manager_observer.h"

class Logic_manager : public Input_manager_observer
{
public:
    Logic_manager();
    void update();
    std::shared_ptr<Actors_vector> get_actors();
    std::shared_ptr<Static_actors_vector> get_static_actors();

    void on_keyboard_event( sf::Event e );

private:
    Physics_manager _physics_manager;
    Game_clock _clock;

    std::vector<std::shared_ptr<Controller>> _controllers;
    Controller _player_controller;
    std::shared_ptr<Dynamic_actor> _player_actor;
    
    std::shared_ptr<Actors_vector> _actors;
    std::shared_ptr<Static_actors_vector> _static_actors;

    int64_t _last_time_update_us;
};
