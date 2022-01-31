#include "controller.h"

void Controller::attach_to_actor( std::shared_ptr<Dynamic_actor>& actor )
{
    _actor = actor;
}

void Controller::move_right()
{
    _actor->add_speed_x( _speed_x );       
}

void Controller::move_left()
{
    _actor->add_speed_x( -_speed_x );
}

void Controller::move_up()
{
    _actor->add_speed_y( -_speed_y );       
}

void Controller::move_down()
{
    _actor->add_speed_y( _speed_y );
}

void Controller::stop_movement_right()
{
    _actor->add_speed_x( -_speed_x );
}

void Controller::stop_movement_left()
{
    _actor->add_speed_x( _speed_x );
}

void Controller::stop_movement_up()
{
    _actor->add_speed_y( _speed_y );
}

void Controller::stop_movement_down()
{
    _actor->add_speed_y( -_speed_y );
}
