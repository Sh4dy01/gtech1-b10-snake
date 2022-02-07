#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "snake.hpp"

#define PIXELS 48
#define SCREEN_SIZE (PIXELS * SQUARES)
#define FRAME_RATE 20

using namespace std;

class MainSDLWindow{

public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(Segment *head, Fruit *fruit);
    void CheckForQuit();

    SDL_Renderer *GetRenderer();
    bool GetGameState();

private:
    bool IsGameRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect map, square;
};