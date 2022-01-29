#include <iostream>
#include "graphics_manager.h"
#define DEBUG
#include "util.h"

int main()
{
    debug_print("Enter\n");
    // TODO add input manager
    Graphics_manager graphics;
    graphics.main_loop();
    return 0;
}