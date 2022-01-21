#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Uint32 frame_rate = 20;

class MainSDLWindow{

    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char title[], int width, int height);
    SDL_Renderer *GetRenderer();
    SDL_Rect GetRect();

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect rect;
};
