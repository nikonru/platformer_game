#pragma once

#include <SFML/Graphics.hpp>

class Input_manager_observer
{
private:
    /* data */
public:
    virtual ~Input_manager_observer() = default;
    virtual void on_keyboard_event( sf::Event e ) = 0;
};