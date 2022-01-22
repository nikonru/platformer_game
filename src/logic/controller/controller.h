#pragma once

#include "actor.h"
#include <memory>

class controller
{
public:
    controller( std::shared_ptr<actor> actor );

    void move_right();
    void move_left();
    void move_up();
    void move_down();

private:
    std::shared_ptr<actor> _actor;
};
