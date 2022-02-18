#include "graphics_manager.h"
#define DEBUG
#include "util.h"
#include "content_manager.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

Graphics_manager::Graphics_manager() {
    Content_manager::init();
    debug_print("post init\n");
    _manager = std::make_shared<Logic_manager>();
     Texture_data td = Content_manager::get_texture_data(Content_manager::BACKGROUND);
    _background.setTexture( td.texture );
    _background.setTextureRect( td.rect );
    _input_manager.add_observer( _manager );
}

void Graphics_manager::main_loop() {
    sf::View mv(sf::FloatRect( sf::Vector2f(0.f, 0.f), sf::Vector2f(1920.f, 1080.f)));
    _main_window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1080, 720), "Game!");
    _main_window->setView(mv);
    _main_window->setFramerateLimit(120);
    _main_window->setKeyRepeatEnabled( false );

    sf::Clock clock;
    int frame_counter = 0;
    
    while (_main_window->isOpen()) {
        processing_events();
       
        if (frame_counter == 20) {
            frame_counter = 0;
            //debug_print("FPS: %.2f\n", (20 / clock.restart().asSeconds()));
        }
        frame_counter++;

        _manager->update();

        auto actors = _manager->get_actors();
        auto static_actors = _manager->get_static_actors();

        _main_window->clear(sf::Color(66, 145, 255)); //light blue

        _main_window->draw(_background);

        for (auto& a: actors->vector)
            _main_window->draw(a->get_sprite());

        for (auto& a: static_actors->vector)
             _main_window->draw(a->get_sprite());
        _main_window->display();  
    }
}

void Graphics_manager::processing_events() {
    sf::Event event;

    while (_main_window->pollEvent(event)) {

        _input_manager.on_event( event );

        if (event.type == sf::Event::Closed) {
            _main_window->close();
        }
    }
}

void Graphics_manager::set_event_callback(sf::Event::EventType type, event_callback cb) {
    _subscribers_to_events[type].push_back(cb);
}
