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
    void AddSnake();
    void CheckBorders();
    void GenerateFruit();

    SDL_Renderer *GetRenderer();
    bool GetGameState();
    int GetFrameRate();
    int GetPixels();
    int GetSquares();

    private:
    int width, height;
    int score;
    bool IsGameRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect map, Ghead, Gfruit;
};