#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Grille de 20 carrés de 32*32
class MainSDLWindow{

    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw();
    void CheckForQuit();

    SDL_Renderer *GetRenderer();
    bool GetGameState();
    int GetFrameRate();

    private:
    int width, height, nbrSquare, pixels, dir;
    bool IsGameRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect playground, rect;
    Uint32 frame_rate;
};