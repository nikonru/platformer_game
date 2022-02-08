#include <iostream>
#include "graphics_manager.h"
#define DEBUG
#include "util.h"
#include "content_manager.h"

int main()
{
    debug_print("Enter\n");
    Content_manager::init();
    // TODO add input manager
    Graphics_manager graphics;
    graphics.main_loop();
    return 0;
}