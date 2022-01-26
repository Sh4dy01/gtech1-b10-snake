#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
    
    this->nbrSquare = 20;
    this->pixels = 32;
    this->width = nbrSquare * pixels;
    this->height = width;
    this->IsGameRunning = true;
    this->frame_rate = 20;
    this->dir = 0;

    this->playground.h = width - pixels * 2;
    this->playground.w = playground.h;
    this->playground.x = pixels;
    this->playground.y = playground.x;

    this->rect.x = width/2;
    this->rect.y = height/2;
    this->rect.w = pixels;
    this->rect.h = pixels;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int MainSDLWindow::Init(){
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

//Draw the playground
void MainSDLWindow::Draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &playground);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rect);
}

//Quit the game
void MainSDLWindow::CheckForQuit(){
    SDL_Event event;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            IsGameRunning = false;
        }
    }
}

SDL_Renderer *MainSDLWindow::GetRenderer(){return renderer;}
bool MainSDLWindow::GetGameState(){return IsGameRunning;}
int MainSDLWindow::GetFrameRate(){return frame_rate;}