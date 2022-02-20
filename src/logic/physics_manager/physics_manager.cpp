#include "physics_manager.h"

Physics_manager::Physics_manager()
{
   _world.SetDebugDraw( &_debug_render );
    uint32_t flags = 0;
   //  flags += b2Draw::e_aabbBit;
   //  flags += b2Draw::e_centerOfMassBit;
    flags += b2Draw::e_jointBit;
    flags += b2Draw::e_pairBit;
    flags += b2Draw::e_shapeBit;
    _debug_render.SetFlags( flags );
}

void Physics_manager::update( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors, int64_t delta_time_us )
{

   float delta_time_s = delta_time_us/1'000'000.f;

   _world.Step( delta_time_s, 64, 64 );

   for( auto& actor: actors->vector )
   {
      actor->update_sprite();
   }

   for( auto& actor: static_actors->vector )
   {
      actor->update_sprite();
   }
}

void Physics_manager::init_actors( const std::shared_ptr<Actors_vector>& actors, const std::shared_ptr<Static_actors_vector>& static_actors )
{
   for( auto& actor: actors->vector )
   {
      actor->init_physics( _world );
   }

   for( auto& actor: static_actors->vector )
   {
      actor->init_physics( _world );
   }
}

void Physics_manager::debug_draw()
{
   _world.DebugDraw();
}
