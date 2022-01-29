#include "input_manager.h"
#define DEBUG
#include "util.h"

Input_manager::Input_manager(Graphics_manager *gm) 
{
    gm->set_event_callback(sf::Event::KeyPressed, keyboard_callback);
}

bool Input_manager::get_button(Input_button button) 
{
    return false;//button >= 0 && button < INPUT_BUTTON_COUNT && _buttons[button]; 
}

float Input_manager::get_axis(Input_axis axis) 
{
    return 0;//axis >= 0 && axis < INPUT_AXIS_COUNT? _axises[axis]: 0;
}

void Input_manager::keyboard_callback(sf::Event e) {
    if (e.key.code == sf::Keyboard::Key::W) {
        _axises[INPUT_AXIS_X] = 1;
    }
    if (e.key.code == sf::Keyboard::Key::S) {
        // Input_manager::_axises[INPUT_AXIS_X] = -1;
    } 
}
