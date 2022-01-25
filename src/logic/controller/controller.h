#pragma once

#include "actor.h"
#include <memory>

class Controller
{
public:
   Controller( std::shared_ptr<Actor>& actor );

   void move_right();
   void move_left();
   void move_up();
   void move_down();
   //TODO how to implement set position and  check of coordinates at the same time
private:
   std::shared_ptr<Actor> _actor;
};
