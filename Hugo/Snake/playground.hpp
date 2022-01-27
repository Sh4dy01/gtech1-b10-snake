#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include "snake.hpp"

using namespace std;

//Grille de 20 carrés de 32*32
class MainSDLWindow{

    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw();
    void CheckForQuit();
    void AddSnake();

    SDL_Renderer *GetRenderer();
    SDL_Rect GetSnake();
    bool GetGameState();
    int GetFrameRate();
    int GetPixels();

    void SetSnake(SDL_Rect snake);

    private:
    int width, height, nbrSquare, pixels;
    bool IsGameRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect map, fruit, head, segment;
    Uint32 frame_rate;
};