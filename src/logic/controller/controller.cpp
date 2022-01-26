#include "controller.h"

void Controller::attach_to_actor( std::shared_ptr<Actor>& actor )
{
    _actor = actor;
}