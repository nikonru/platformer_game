#include "physics_manager.h"

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time_us )
{

   float delta_time_s = delta_time_us/1'000'000.f;
   
   const float g = 90;

   for( auto& actor: actors->vector )
   {
      bool is_collide_x = false;
      bool is_collide_y = false;

      auto acceleration_x = actor->get_acceleration_x();
      auto acceleration_y = actor->get_acceleration_y();

      auto boost_x = acceleration_x * delta_time_s;
      auto boost_y = acceleration_y * delta_time_s;

      actor->add_speed_x( boost_x );
      actor->add_speed_y( boost_y );

      actor->add_speed_y( g * delta_time_s );

      auto speed_x = actor->get_speed_x(); 
      auto speed_y = actor->get_speed_y();

      auto movement_x = speed_x * delta_time_s;
      auto movement_y = speed_y * delta_time_s;

      //TODO it can be better

      for( auto& static_actor: static_actors->vector)
      {
         bool x_collision = check_expected_collision_by_x( *actor, *static_actor, movement_x );
         bool y_collision = check_expected_collision_by_y( *actor, *static_actor, movement_y );
         
         if ( x_collision || y_collision )
            actor->on_collision( *static_actor );

         if( x_collision )
            is_collide_x = true;
         
         if( y_collision )
            is_collide_y = true;
      }

      for( auto& another_actor: actors->vector)
      {
         if( actor == another_actor )
            continue;

         if( check_collision( *actor, *another_actor ) )
            actor->on_collision( *another_actor );
      }

      if( !is_collide_x )
         actor->move_x( movement_x );

      if( !is_collide_y )
         actor->move_y( movement_y );
      else
         actor->set_speed_y( 0 );
   }
}

bool Physics_manager::check_collision( Actor& actor, Actor& static_actor )
{
   auto collsion_a = actor.get_collision();
   auto collsion_b = static_actor.get_collision();

   auto position_a = collsion_a.getPosition();
   auto position_b = collsion_b.getPosition();

   auto size_a = collsion_a.getSize();
   auto size_b = collsion_b.getSize();

   return check_rectangle_collision( position_a.x, position_a.y, size_a.x, size_a.y, position_b.x, position_b.y, size_b.x, size_b.y );
}

bool Physics_manager::check_expected_collision_by_x( Actor& actor, Actor& static_actor, float delta_x  )
{
   auto collsion_a = actor.get_collision();
   auto collsion_b = static_actor.get_collision();

   auto position_a = collsion_a.getPosition();
   auto position_b = collsion_b.getPosition();

   auto size_a = collsion_a.getSize();
   auto size_b = collsion_b.getSize();

   return check_rectangle_collision( position_a.x + delta_x, position_a.y, size_a.x, size_a.y, position_b.x, position_b.y, size_b.x, size_b.y );
}

bool Physics_manager::check_expected_collision_by_y( Actor& actor, Actor& static_actor, float delta_y  )
{
   auto collsion_a = actor.get_collision();
   auto collsion_b = static_actor.get_collision();

   auto position_a = collsion_a.getPosition();
   auto position_b = collsion_b.getPosition();

   auto size_a = collsion_a.getSize();
   auto size_b = collsion_b.getSize();

   return check_rectangle_collision( position_a.x, position_a.y + delta_y, size_a.x, size_a.y, position_b.x, position_b.y, size_b.x, size_b.y );
}

bool Physics_manager::check_rectangle_collision( float a_x, float a_y, float a_width, float a_height, float b_x, float b_y, float b_width, float b_height  )
{
   if( a_x < b_x + b_width 
       && a_x + a_width > b_x
       && a_y < b_y + b_height
       && a_height + a_y > b_y )
   {
      return true;
   }
   else
   {
      return false;
   }
}
