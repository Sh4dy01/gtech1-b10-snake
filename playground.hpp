#pragma once

#include "snake.hpp"
#include "constants.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>


class MainSDLWindow{

public:
    MainSDLWindow();
    ~MainSDLWindow();

    int Init();
    void Draw(Segment *head, Fruit *fruits, bool ballCollection[SET], int length, int score, int level);
    SDL_Texture *CreateTextureFromImage(const char path[]);
    void DrawText(const char name[]);
    void DrawText(const char name[], int score);

    void CheckForQuit();

    SDL_Renderer *GetRenderer();
    bool GetGameState();

    void SetBallTexture(int star);

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
    SDL_Texture *headTexture, *bodyTexture, *tailTexture, *ballTexture, *malusBallTexture, *winBallTexture, *scoreTexture;
    TTF_Font *font;
};