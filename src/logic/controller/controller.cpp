#include "controller.h"

void Controller::attach_to_actor( std::shared_ptr<Actor>& actor )
{
    _actor = actor;
}

void Controller::move_right()
{
    _actor->set_speed_x( 30 );       
}

void Controller::move_left()
{
    _actor->set_speed_x( -30 );
}

void Controller::stop_movement_horizontally()
{
    _actor->set_speed_x( 0 );
}