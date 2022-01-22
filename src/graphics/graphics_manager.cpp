#include "graphics_manager.h"


#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
 
graphics_manager::graphics_manager() {
    manager = std::make_shared<Logic_manager>();
}



void graphics_manager::main_loop() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game!");
    
    sf::Clock clock;
    int frame_counter = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (frame_counter == 10) {
            frame_counter = 0;
            std::cout << "FPS " << (10 / clock.restart().asSeconds()) << std::endl;
        }
        frame_counter++;

        //auto actors = manager->get_actors();

        window.clear(sf::Color(66, 145, 255)); //light blue
        //for (auto a: actors)
        //window.draw(a->get_sprite());
        window.display();  
    }
}