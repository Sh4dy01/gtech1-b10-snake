#include <SDL2/SDL.h>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


class MainSDLWindow{
    public:
    MainSDLWindow(){
        this->window,renderer = NULL;
    }
    ~MainSDLWindow(){
        SDL_Delay(10000);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    int Init(const char title[], int largeur, int hauteur){
        //Création de la fenêtre
        window = SDL_CreateWindow("Une fenêtre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur, hauteur, SDL_WINDOW_RESIZABLE);
        if (window == NULL){
            cout << "Erreur lors de la creation de la fenêtre:" << SDL_GetError();
            return EXIT_FAILURE;
        }
        SDL_SetWindowTitle(window, title);
        
        //Création du renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL){
            cout << "Erreur lors de la creation du rendu:" << SDL_GetError();
            return EXIT_FAILURE;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Change la couleur de fond

        return EXIT_SUCCESS;
    }
    SDL_Renderer *GetRenderer(void){return renderer;};

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    
};
