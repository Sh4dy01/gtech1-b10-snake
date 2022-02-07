#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window = NULL;
    this->renderer = NULL;
    
    this->IsGameRunning = true;

    this->map.h = SCREEN_SIZE - PIXELS * 2;
    this->map.w = map.h;
    this->map.x = PIXELS;
    this->map.y = map.x;

    this->square.w = PIXELS;
    this->square.h = square.w;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

int MainSDLWindow::Init(){
    //Création de la fenêtre
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE, SCREEN_SIZE, SDL_WINDOW_RESIZABLE);
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
/*
    SDL_Surface *surface = NULL; 
    SDL_Texture *texture, *tmp = NULL;

    surface = SDL_LoadBMP("test.bmp");
    if(NULL == surface)
    {
        cout << "Erreur SDL_LoadBMP :" << SDL_GetError();
        return EXIT_FAILURE;
    }

    tmp = SDL_CreateTextureFromSurface(renderer, surface);
    if(NULL == tmp)
    {
        cout << "Erreur SDL_CreateTextureFromSurface :" << SDL_GetError();
        return EXIT_FAILURE;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
                                SDL_TEXTUREACCESS_TARGET, surface->w, surface->h);
    if(NULL == texture) 
    {
        cout << "Erreur SDL_CreateTextureFromSurface :" << SDL_GetError();
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(renderer, texture); // La cible de rendu est maintenant texture. 
    SDL_RenderCopy(renderer, tmp, NULL, NULL); // On copie tmp sur texture 
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface); */

    return EXIT_SUCCESS;
}


//Draw the playground
void MainSDLWindow::Draw(Segment *head, Fruit *fruit){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &map);
    
    square.x = fruit->GetX() * PIXELS;
    square.y = fruit->GetY() * PIXELS;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &square);

    //SDL_SetRenderTarget(renderer, NULL);

    square.x = head->GetX();
    square.y = head->GetY();
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &square);

    Segment *body;
    body = head;
    while (body->CheckNext())
    {
        body = body->GetNext();
        square.x = body->GetX();
        square.y = body->GetY();
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &square);
    }

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