#include "physics_manager.h"

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time_us )
{

   float delta_time_s = delta_time_us/1'000'000.f;

   _world.Step( delta_time_s, 6, 2 );

   for( auto& actor: actors->vector )
   {
      actor->update_position();
   }
}

void Physics_manager::init_actors( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors )
{
   for( auto& actor: actors->vector )
   {
      b2Body* body = _world.CreateBody( &actor->get_body_def() );
      actor->set_body( body );
   }

   for( auto& actor: static_actors->vector )
   {
      b2Body* body = _world.CreateBody( &actor->get_body_def() );
      actor->set_body( body );
   }
}
