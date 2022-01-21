#include "exercice1.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
}
MainSDLWindow::~MainSDLWindow(){
    SDL_Delay(10000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
int MainSDLWindow::Init(const char title[], int largeur, int hauteur){
    //Création de la fenêtre
        window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, largeur, hauteur, SDL_WINDOW_RESIZABLE);
        if (window == NULL){
            cout << "Erreur lors de la creation de la fenêtre:" << SDL_GetError();
            return EXIT_FAILURE;
        }
        
        //Création du renderer
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == NULL){
            cout << "Erreur lors de la creation du rendu:" << SDL_GetError();
            return EXIT_FAILURE;
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); //Change la couleur de fond

        return EXIT_SUCCESS;
}
SDL_Renderer *MainSDLWindow::GetRenderer(){return renderer;}

int main()
{
    MainSDLWindow main_window;
    main_window.Init("Manipulation de la SDL2", 600, 600);
}
