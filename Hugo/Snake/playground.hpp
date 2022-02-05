#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#include "snake.hpp"

#define PIXELS 32
#define SCREEN_SIZE (PIXELS*SQUARES)

#define SCORE_TO_ADD 10
#define SPEED 4
#define FRAME_RATE 20

using namespace std;

class MainSDLWindow{

    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(Segment* head);
    void CheckForQuit();
    void AddSnake();
    void CheckBorders();
    bool CheckFruit();
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
    SDL_Rect map;
    SDL_Rect Ghead;
    SDL_Rect Gfruit;
    Fruit fruit;
};