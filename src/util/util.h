#pragma once

#include "cstdio"
#include "b2GLDraw.h"

#ifdef DEBUG
#define DEBUG_MODE 1
#else
#define DEBUG_MODE 0
#endif

#define debug_print(msg, ...) \
do { \
    if (DEBUG_MODE) { \
        fprintf(stdout, "%s(): " msg, __func__, ##__VA_ARGS__); \
    } \
} while(0)

#define debug_var(var) std::cout << #var << ": " << var << std::endl;