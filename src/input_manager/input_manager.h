#pragma once

#include "graphics_manager.h"

#include <memory>
#include <SFML/Graphics.hpp>

enum Input_axis {
    INPUT_AXIS_X = 0,
    INPUT_AXIS_Y,
    // TODO add mouse axis 
    INPUT_AXIS_COUNT
};

enum Input_button {
    INPUT_BUTTON_FIRE1 = 0,
    INPUT_BUTTON_FIRE2,
    // TODO add more buttons 
    INPUT_BUTTON_COUNT
};

class Input_manager
{
private:
    std::shared_ptr<sf::RenderWindow> _window;

    static bool _buttons[INPUT_BUTTON_COUNT];
    static float _axises[INPUT_AXIS_COUNT];

    static void keyboard_callback(sf::Event e);

public:
    Input_manager(Graphics_manager *gm);
    /**
     * Get axis state.
     * @param axis the axis for which the state needs to be returned.
     * @return value from -1 to 1.
     */
    float get_axis(Input_axis axis);
    /**
     * Get button state.
     * @param button the button for which the state needs to be returned.
     * @return true if button presed, else false.
     */
    bool get_button(Input_button button);
};
