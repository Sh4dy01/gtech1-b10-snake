#pragma once

#include <SDL2/SDL.h>
#include "snake.hpp"

#define PIXELS 32
#define SQUARES 20
#define ARRAY_SIZE ((SQUARES-2)*(SQUARES-2))
#define SCREEN_SIZE (PIXELS * SQUARES)
#define FRAME_RATE 20

using namespace std;

class MainSDLWindow{

public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(Segment *head, Fruit *fruit, int score);
    void CheckForQuit();

    SDL_Renderer *GetRenderer();
    bool GetGameState();

private:
    bool IsGameRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect map, square;
    SDL_Texture *headText, *bodyText, *tailText, *ballText;
};