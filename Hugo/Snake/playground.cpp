#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window = NULL;
    this->renderer = NULL;
    
    this->width = SQUARES * PIXELS;
    this->height = width;
    this->IsGameRunning = true;

    this->map.h = width - PIXELS * 2;
    this->map.w = map.h;
    this->map.x = PIXELS;
    this->map.y = map.x;

    this->Ghead.h = PIXELS;
    this->Ghead.w = PIXELS,
    this->Ghead.x = SQUARES / 2 * PIXELS;
    this->Ghead.y = Ghead.x;

    this->Gfruit.w = PIXELS;
    this->Gfruit.h = PIXELS;

}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
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
void MainSDLWindow::Draw(Segment *head){

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &map);
    
    this->Gfruit.x = fruit.GetX() * PIXELS;
    this->Gfruit.y = fruit.GetY() * PIXELS;
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &Gfruit);

    //SDL_SetRenderTarget(renderer, NULL);

    Ghead.x = head->GetX();
    Ghead.y = head->GetY();
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &Ghead);

    SDL_Rect Gbody;
    Gbody.w = PIXELS;
    Gbody.h = PIXELS;

    Segment *body;
    body = head;
    while (body->CheckNext())
    {
        body = body->GetNext();
        Gbody.x = body->GetX();
        Gbody.y = body->GetY();
        SDL_SetRenderDrawColor(renderer, 0, 200, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &Gbody);
    }

    SDL_RenderPresent(renderer); //Refresh the renderer
}

bool MainSDLWindow::CheckFruit(){

    if (Ghead.x == Gfruit.x && Ghead.y == Gfruit.y)
    {
        score += SCORE_TO_ADD;
        fruit.GenerateFruit();
        Gfruit.x = fruit.GetX() * PIXELS;
        Gfruit.y = fruit.GetY() * PIXELS;
        return true;
    }
    return false;
}

void MainSDLWindow::GenerateFruit(){
    fruit.GenerateFruit();
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
int MainSDLWindow::GetPixels(){return PIXELS;}
int MainSDLWindow::GetSquares(){return SQUARES;}