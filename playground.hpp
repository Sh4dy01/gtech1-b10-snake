#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "snake.hpp"

#define PIXELS 32
#define SCREEN_SIZE (PIXELS * SQUARES)
#define FRAME_RATE 20

using namespace std;

class MainSDLWindow{

public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(Segment *head, Fruit *fruits, int length, int ballCount, int score);
    void CheckForQuit();
    SDL_Texture *CreateTextureFromImage(const char path[]);
    void DrawScore(int score, const char name[]);

    SDL_Renderer *GetRenderer();
    bool GetGameState();

private:
    bool IsGameRunning;
    int highScore, ballCount;
    const char *scoreText;

    string scoreString;
    string ballString;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect map, square, scoreArea;
    SDL_Surface *scoreSurface;
    SDL_Texture *headTexture, *bodyTexture, *tailTexture, *ballTexture, *mBallTexture, *scoreTexture;
    TTF_Font *font;
};