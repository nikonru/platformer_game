#include "dynamic_actor.h"

class Player_actor : public Dynamic_actor
{
private:
    unsigned int _hp = 100;
public:
    Player_actor( sf::Vector2f position, sf::Vector2f speed, Texture_data sprite, sf::FloatRect collision );
    unsigned int get_hp();
};
