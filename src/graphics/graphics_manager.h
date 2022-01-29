#pragma once

#include "logic_manager.h"
#include "physics_manager.h"

#include <map>

typedef void (*event_callback)(sf::Event e);

class Graphics_manager {
private:
    std::shared_ptr<Logic_manager> _manager;
    std::shared_ptr<sf::RenderWindow> _main_window;

    std::map<sf::Event::EventType, std::vector<event_callback>> _subscribers_to_events;

    void processing_events();
public:
    Graphics_manager();
    void main_loop();
    void set_event_callback(sf::Event::EventType type, event_callback cb);
};


