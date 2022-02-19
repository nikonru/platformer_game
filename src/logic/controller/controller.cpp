#include "controller.h"

void Controller::attach_to_actor( std::shared_ptr<Dynamic_actor> actor )
{
    _actor = actor;
}

void Controller::move_right()
{
    _actor->move( get_horizontal_velocity() );       
}

void Controller::move_left()
{
    _actor->move( -get_horizontal_velocity() );
}

void Controller::move_up()
{
    _actor->move( -get_vertical_velocity() );       
}

void Controller::move_down()
{
    _actor->move( get_vertical_velocity() );
}

sf::Vector2f Controller::get_horizontal_velocity()
{
    return sf::Vector2f( _velocity.x, 0 );
}

sf::Vector2f Controller::get_vertical_velocity()
{
    return sf::Vector2f( 0, _velocity.y );
}
