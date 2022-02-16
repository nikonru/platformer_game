#include "content_manager.h"
#include <exception>

using namespace std;

const string PATH_TO_CONTENT = "content/";
const string PATH_TO_TEXTURES = PATH_TO_CONTENT + "texture/";

std::array<sf::Texture, Content_manager::COUNT> Content_manager::textures;
std::array<sf::IntRect, Content_manager::COUNT> Content_manager::texture_rect;

Texture_data Content_manager::get_texture_data(enum type type) 
{
    Texture_data td = { textures[type], texture_rect[type] };
    return td;
}

void Content_manager::init() 
{
    if( !textures[PLAYER].loadFromFile( PATH_TO_TEXTURES+"player.png" ) )
        throw exception();
    texture_rect[PLAYER] = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(64,108));

    if( !textures[TILE_BOX].loadFromFile( PATH_TO_TEXTURES+"texture.png") )
        throw exception();
    texture_rect[TILE_BOX] = sf::IntRect(sf::Vector2i(128,128), sf::Vector2i(64,64));

    if( !textures[BACKGROUND].loadFromFile( PATH_TO_TEXTURES+"background.png") )
        throw exception();
    texture_rect[BACKGROUND] = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(1920, 1080));
}