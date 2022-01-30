#include "physics_manager.h"

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time_us )
{

   float delta_time_s = delta_time_us/1'000'000.f;
   
   for( auto& actor: actors->vector )
   {
      bool is_collide_x = false;
      bool is_collide_y = false;

      auto speed_x = actor->get_speed_x(); 
      auto speed_y = actor->get_speed_y();

      auto acceleration_x = actor->get_acceleration_x();
      auto acceleration_y = actor->get_acceleration_y();

      auto movement_x = speed_x * delta_time_s;
      auto movement_y = speed_y * delta_time_s;

      auto boost_x = acceleration_x * delta_time_s;
      auto boost_y = acceleration_y * delta_time_s;

      //TODO figure out new algorithm for collision this one is terrible

      actor->move_x( movement_x );
      for( auto& static_actor: static_actors->vector)
      {
         if ( check_collision( *actor, *static_actor ) )
         {
            is_collide_x = true;
            actor->on_collision( *static_actor );
         }
      }
      if( is_collide_x )
      {
         actor->move_x( -movement_x );
      }

      actor->move_y( movement_y );
      for( auto& static_actor: static_actors->vector)
      {
         if ( check_collision( *actor, *static_actor ) )
         {
            is_collide_y = true;
            actor->on_collision( *static_actor );
         }
      }
      if( is_collide_y )
      {
         actor->move_y( -movement_y );
      }

      actor->add_speed_x( boost_x );
      actor->add_speed_y( boost_y );
       
      const float g = 0;//45;

      actor->add_speed_y( g * delta_time_s );

   }
    
   for( auto& static_actor: static_actors->vector)
   {
        //todo
   }
}

bool Physics_manager::check_collision( Dynamic_actor& actor, Static_actor& static_actor  )
{
   auto collsion_a = actor.get_collision();
   auto collsion_b = static_actor.get_collision();

   auto position_a = collsion_a.getPosition();
   auto position_b = collsion_b.getPosition();

   auto size_a = collsion_a.getSize();
   auto size_b = collsion_b.getSize();

   if( position_a.x < position_b.x + size_b.x 
       && position_a.x + size_a.x > position_b.x
       && position_a.y < position_b.y + size_b.y
       && size_a.y + position_a.y > position_b.y )
   {
      return true;
   }
   else
   {
      return false;
   }
}
