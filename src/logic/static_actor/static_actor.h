#pragma once

#include <vector>
#include <memory>

class Static_actor
{
public:
    int x, y;
private:

};

struct Static_actors_vector
{
    std::vector<std::shared_ptr<Static_actor>> vector;
};
