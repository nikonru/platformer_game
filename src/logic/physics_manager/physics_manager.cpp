#include "physics_manager.h"

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time_us )
{

   float delta_time_s = delta_time_us/1'000'000.f;
   
   for( auto& actor: actors->vector )
   {
      actor->move_x( actor->get_speed_x() * delta_time_s );
      actor->move_y( actor->get_speed_y() * delta_time_s );

      actor->add_speed_x( actor->get_acceleration_x() * delta_time_s );
      actor->add_speed_y( actor->get_acceleration_y() * delta_time_s );
       
      const float g = 45;

      actor->add_speed_y( g * delta_time_s );
   }
    
   for( auto& static_actor: static_actors->vector)
   {
        //todo
   }
}
