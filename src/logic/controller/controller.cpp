#include "controller.h"

void Controller::connect_to_actor( std::shared_ptr<Actor>& actor )
{
    _actor = actor;
}