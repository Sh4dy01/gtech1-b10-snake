#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "snake.hpp"


using namespace std;

//Grille de 20 carrés de 32*32
class MainSDLWindow{

    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(int score);
    void CheckForQuit();
    void AddSnake();
    void score();

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
    SDL_Rect map;
    SDL_Rect fruit;
    SDL_Rect head;
    SDL_Rect segment;
    SDL_Rect scoreArea;
    SDL_Surface *scoreSurface;
    TTF_Font* font;
    SDL_Color couleurScore;
    SDL_Texture *scoreTexture;
    char *scoreText;
    Uint32 frame_rate;
};