#include "logic_manager.h"

#define DEBUG
#include "util.h"

using namespace std;

Logic_manager::Logic_manager() 
{
    _last_time_update_us = 0;

    _actors = make_shared<Actors_vector>();
    _static_actors = make_shared<Static_actors_vector>();

    auto player = make_shared<Actor>();
    _player_controller.attach_to_actor( player );

    auto block = make_shared<Static_actor>();

    _actors->vector.push_back( player );
    _static_actors->vector.push_back( block );

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
                case sf::Keyboard::Key::W:  
                case sf::Keyboard::Key::S:
                    _player_controller.stop_movement_vertically();
                    break;   

                case sf::Keyboard::Key::D:
                case sf::Keyboard::Key::A:
                    _player_controller.stop_movement_horizontally();
                    break;    
            }
            break;
    }
}