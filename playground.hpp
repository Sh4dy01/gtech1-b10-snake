#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "snake.hpp"

using namespace std;

class MainSDLWindow{

public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init();
    void Draw(Segment *head, Fruit *fruits, bool ballStars[SET], int length, int score);
    void CheckForQuit();
    SDL_Texture *CreateTextureFromImage(const char path[]);
    void DrawText(const char name[]);
    void DrawText(const char name[], int score);
    void SetBallTexture(int star);
    void DrawSet(int star);

    SDL_Renderer *GetRenderer();
    bool GetGameState();
    bool GetIfWon();

    void CheckIfWon(int length, int turn);

private:
    bool IsGameRunning;
    bool IsGameWon;
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