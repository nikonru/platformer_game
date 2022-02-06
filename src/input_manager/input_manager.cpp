#include "input_manager.h"
#define DEBUG
#include "util.h"

#include <iostream>

using namespace std;

void Input_manager::on_event( sf::Event e )
{
    notify_observers( e );
}

void Input_manager::notify_observers( sf::Event e )
{
    if ( e.type == sf::Event::KeyPressed || e.type == sf::Event::KeyReleased )
    {
        for( auto observer: _observers )
        {
            observer->on_keyboard_event( e );
        }
    }
}

void Input_manager::add_observer( std::shared_ptr<Input_manager_observer> observer )
{
    _observers.push_back( observer );
}
