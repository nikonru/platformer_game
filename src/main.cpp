#include <iostream>
#include "graphics_manager.h"
#define DEBUG
#include "util.h"
#include "content_manager.h"

int main()
{
    try
    {
        debug_print("Enter\n");
        Content_manager::init();
        // TODO add input manager
        debug_print("pre init\n");
        Graphics_manager graphics;
        debug_print("init\n");
        graphics.main_loop();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}