#pragma once

#include "dynamic_actor.h"
#include <memory>

class Controller 
{
public:

   void attach_to_actor( std::shared_ptr<Dynamic_actor> actor );

   void move_right();
   void move_left();
   void move_up();
   void move_down();
   //TODO how to implement set position and  check of coordinates at the same time

   void stop_movement_right();
   void stop_movement_left();
   void stop_movement_up();
   void stop_movement_down();
private:
   std::shared_ptr<Dynamic_actor> _actor;

   sf::Vector2f _speed = sf::Vector2f( 30, 180 );
};
