#include "graphics_manager.h"
#define DEBUG
#include "util.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

Graphics_manager::Graphics_manager() {
    _manager = std::make_shared<Logic_manager>();
}

void Graphics_manager::main_loop() {
    _main_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(400, 400), "Game!");
    _main_window->setFramerateLimit(120);

    sf::Clock clock;
    int frame_counter = 0;
    
    while (_main_window->isOpen()) {
        processing_events();
       
        if (frame_counter == 20) {
            frame_counter = 0;
            debug_print("FPS: %.2f\n", (20 / clock.restart().asSeconds()));
        }
        frame_counter++;

        _manager->update();

        auto actors = _manager->get_actors();

        _main_window->clear(sf::Color(66, 145, 255)); //light blue
        for (auto& a: actors->vector)
             _main_window->draw(a->get_sprite());
        _main_window->display();  
    }
}

void Graphics_manager::processing_events() {
    sf::Event event;
    while (_main_window->pollEvent(event)) {

        for (event_callback cb :_subscribers_to_events[event.type]) {
           cb(event);     
        }

        if (event.type == sf::Event::Closed) {
            _main_window->close();
        }
    }
}

void Graphics_manager::set_event_callback(sf::Event::EventType type, event_callback cb) {
    _subscribers_to_events[type].push_back(cb);
}