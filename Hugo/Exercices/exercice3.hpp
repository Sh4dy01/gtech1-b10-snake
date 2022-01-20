#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

Uint32 frame_rate = 20;

class MainSDLWindow{

    public:
    MainSDLWindow(){
        this->window,renderer = NULL;
    }
    ~MainSDLWindow(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    int Init(const char title[], int width, int height);

    SDL_Renderer *GetRenderer(){return renderer;};
    SDL_Rect GetRect(){return rect;}

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect rect;
};
