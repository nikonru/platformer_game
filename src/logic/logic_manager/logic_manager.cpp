#include "logic_manager.h"

#include "world_generator.h"

#define DEBUG
#include "util.h"

using namespace std;

Logic_manager::Logic_manager() 
{
    _last_time_update_us = 0;

    _actors = make_shared<Actors_vector>();
    _static_actors = make_shared<Static_actors_vector>();

    auto world = World_generator::make_world( 228 );

    auto player = World_generator::make_player( world.player_position );
    _player_controller.attach_to_actor( player );

    auto block = World_generator::make_tile_box( 100, 120 );

    _actors->vector.push_back( player );
    _static_actors = world.static_actors;

    _physics_manager.init_actors( _actors, _static_actors );

    _clock.start();
}

void Logic_manager::update()
{
    auto current_time = _clock.get_time();
    int64_t delta_time_us = current_time.asMicroseconds() - _last_time_update_us;

    _physics_manager.update( _actors, _static_actors, delta_time_us );
    _last_time_update_us = current_time.asMicroseconds();
}

shared_ptr<Actors_vector> Logic_manager::get_actors()
{
    return _actors;
}

shared_ptr<Static_actors_vector> Logic_manager::get_static_actors()
{
    return _static_actors;
}

void Logic_manager::debug_update()
{
    _physics_manager.debug_draw();
}

void Logic_manager::on_keyboard_event( sf::Event e )
{
    debug_print("log\n");

    switch( e.type )
    {
        case sf::Event::KeyPressed:
            debug_print("%d", int(e.key.code));
            switch(e.key.code)
            {
                case sf::Keyboard::Key::W:
                    _player_controller.move_up();
                    break;   

                case sf::Keyboard::Key::S:
                    _player_controller.move_down();
                    break;   

                case sf::Keyboard::Key::D:
                    _player_controller.move_right();
                    break;

                case sf::Keyboard::Key::A:
                    _player_controller.move_left();
                    break;
            }
            break;

        case sf::Event::KeyReleased:
            switch(e.key.code)
            {
                // case sf::Keyboard::Key::W:  
                //     _player_controller.stop_movement_up();
                //     break;   
                case sf::Keyboard::Key::S:
                    _player_controller.stop_movement_down();
                    break;   

                case sf::Keyboard::Key::D:
                    _player_controller.stop_movement_right();
                    break; 
                case sf::Keyboard::Key::A:
                    _player_controller.stop_movement_left();
                    break;    
            }
            break;
    }
}