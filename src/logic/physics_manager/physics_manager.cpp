#include "physics_manager.h"

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors )
{
   for( auto& actor: actors->vector )
   {
       actor->move_x( actor->get_speed_x() );
       actor->move_y( actor->get_speed_y() );

       actor->add_speed_x( actor->get_acceleration_x() );
       actor->add_speed_y( actor->get_acceleration_y() );

       actor->set_acceleration_y( 5 );
   }
    
   for( auto& static_actor: static_actors->vector)
   {
        //todo
   }
}
