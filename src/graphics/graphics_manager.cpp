#include "graphics_manager.h"
#include <SFML/Graphics.hpp>

#include <iostream>
 
graphics_manager::graphics_manager() {
}

void graphics_manager::main_loop() {
    sf::RenderWindow window(sf::VideoMode(400, 400), "Game!");
    
    sf::Clock clock;
    int frame_counter = 0;

    sf::CircleShape circle(200);
    circle.setFillColor(sf::Color::Green);

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

        window.clear(sf::Color(66, 145, 255)); //light blue
        window.draw(circle);
        window.display();  
    }
}