#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <iostream>
#include <windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

// screen
const int FRAME_PER_SECOND = 25;  //fps
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 64;

const int COLOR_KEY_R = 167;
const int COLOR_KEY_G = 175;
const int COLOR_KEY_B = 180;

const int RENDER_DRAW_COLOR = 0Xff;

#define TILE_SIZE 64
#define BLANK 0

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

typedef struct Input{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
};

struct Map{
    int start_x_, start_y_;
    int max_x_, max_y_;
    int tile[MAX_MAP_Y][MAX_MAP_X];
    char* file_name_;
};

#endif
