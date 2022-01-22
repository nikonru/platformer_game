#pragma once

#include "logic_manager.h"
#include "physics_manager.h"

class graphics_manager {
private:
    std::shared_ptr<logic_manager> manager;
public:
    graphics_manager();
    void main_loop();
};



