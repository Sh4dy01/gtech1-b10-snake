#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
    
    this->nbrSquare = 20;
    this->pixels = 32;
    this->width = nbrSquare * pixels;
    this->height = width;
    this->IsGameRunning = true;
    this->frame_rate = 20;

    this->map.h = nbrSquare * pixels - pixels * 2;
    this->map.w = map.h;
    this->map.x = pixels;
    this->map.y = map.x;

    this->head.h = pixels;
    this->head.w = pixels,
    this->head.x = nbrSquare / 2 * pixels;
    this->head.y = head.x;
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
void MainSDLWindow::Draw(int x, int y){
    head.x = x;
    head.y = y;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &map);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &head);

    SDL_RenderPresent(renderer); //Refresh the renderer
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
int MainSDLWindow::GetPixels(){return pixels;}
int MainSDLWindow::GetSquares(){return nbrSquare;}