#pragma once

#include "static_actor.h"
#include "actor.h"
#include <memory>
#include <vector>

class physics_manager
{
public:
    void update();
    std::vector<std::shared_ptr<actor>> get_actors();
    std::vector<std::shared_ptr<static_actor>> get_static_actors();

private:
    std::vector<std::shared_ptr<actor>> _actors;
    std::vector<std::shared_ptr<static_actor>> _static_actors;
};
