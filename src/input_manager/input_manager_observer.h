#pragma once

#include <SFML/Graphics.hpp>

class Input_manager_observer
{
private:
    /* data */
public:
    void on_keyboard_event( sf::Event e );
};