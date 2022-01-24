#include "renderer.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
}
MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
int MainSDLWindow::Init(const char title[], int width, int height){
    //Création de la fenêtre
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
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

    return EXIT_SUCCESS;
}
SDL_Renderer *MainSDLWindow::GetRenderer(){return renderer;}