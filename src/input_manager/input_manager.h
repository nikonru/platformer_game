#pragma once

#include "input_manager_observer.h"

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class Input_manager
{
private:
    void notify_observers( sf::Event e );

    std::vector<std::shared_ptr<Input_manager_observer>> _observers;

public:
    void on_event( sf::Event e );

    void add_observer( std::shared_ptr<Input_manager_observer> observer );
};
