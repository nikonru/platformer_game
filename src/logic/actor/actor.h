#pragma once

#include <memory>
#include "physics_manager.h"

class actor
{
public:

    void on_collision();

    int _x, _y;

    float _speed_x, _speed_y;
    float _acceleration_x, _acceleration_y;

private:
    std::shared_ptr<physics_manager> _physics_manager;
};

