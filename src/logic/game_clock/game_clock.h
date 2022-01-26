#pragma once

#include <SFML/Graphics.hpp>

class Game_clock
{
public:
    Game_clock();

    sf::Time get_time();

    void start();
    void stop();
    void toggle();

private:

    void update_time();

    sf::Clock _clock;

    sf::Time _time;

    bool _is_stopped;
};



