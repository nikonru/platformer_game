#include "game_clock.h"

Game_clock::Game_clock()
: _is_stopped( true )
, _time( _clock.restart() )
{}

sf::Time Game_clock::get_time()
{
    update_time();
    return _time;
}

void Game_clock::start()
{
    _is_stopped = false;
    _clock.restart();
}

void Game_clock::stop()
{
    _is_stopped = true;
}

void Game_clock::toggle()
{
    if( _is_stopped )
        _clock.restart();
        
    _is_stopped = !_is_stopped;
}

void Game_clock::update_time()
{
    if( !_is_stopped )
    {
        _time += _clock.restart();
    }
}
