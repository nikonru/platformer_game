#include <memory>

#include "dynamic_actor.h"
#include "static_actor.h"
#include "content_manager.h"

class World_generator
{
private:
    std::shared_ptr<Static_actor> make_tile_box();
public:
    std::shared_ptr<Dynamic_actor> make_player();
};

