#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class MainSDLWindow{
    public:
    MainSDLWindow(){}
    ~MainSDLWindow(){}

    int Init(const char title[], int largeur, int hauteur){}

    SDL_Renderer *GetRenderer(void){};

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};
