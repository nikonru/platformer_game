#pragma once

#include "dynamic_actor.h"
#include <memory>

class Controller 
{
public:
   void attach_to_actor( std::shared_ptr<Dynamic_actor>& actor );

   void move_right();
   void move_left();
   void move_up();
   void move_down();
   //TODO how to implement set position and  check of coordinates at the same time

   void stop_movement_horizontally();
   void stop_movement_vertically();
private:
   std::shared_ptr<Dynamic_actor> _actor;
};
