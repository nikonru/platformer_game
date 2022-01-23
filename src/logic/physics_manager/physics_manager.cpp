#include "physics_manager.h"

Physics_manager::Physics_manager( std::shared_ptr<Actors_vector> actors, std::shared_ptr<Static_actors_vector> static_actors )
{
   _actors = actors;
   _static_actors = static_actors;
}

void Physics_manager::update()
{
   for( auto& actor: _actors->vector )
   {
       actor->move_x( actor->get_speed_x() );
       actor->move_y( actor->get_speed_y() );

       actor->add_speed_x( actor->get_acceleration_x() );
       actor->add_speed_y( actor->get_acceleration_y() );

       actor->set_acceleration_y( 5 );
   }
    
   for( auto& static_actor: _static_actors->vector)
   {
        //todo
   }
}
