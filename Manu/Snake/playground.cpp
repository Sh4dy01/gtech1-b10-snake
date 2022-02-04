#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
    
    this->nbrSquare = 20;
    this->pixels = 32;
    this->width = nbrSquare * pixels;
    this->height = width;
    this->IsGameRunning = true;
    this->frame_rate = 20;

    this->map.h = width - pixels * 2;
    this->map.w = map.h;
    this->map.x = pixels;
    this->map.y = map.x;

    this->head.h = pixels;
    this->head.w = pixels,
    this->head.x = (width - pixels * 2) / 2;
    this->head.y = head.x;

    this->fruit.h = pixels;
    this->fruit.w = pixels;
    this->fruit.x = 0;
    this->fruit.y = 0;
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

     //Inititialisation du texte
    if(TTF_Init() == -1){
        fprintf(stderr, "erreur d'initialisation de TTF_init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);

    };

    return EXIT_SUCCESS;

}


//Draw the playground
void MainSDLWindow::Draw(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer); //Refresh the renderer
}

void MainSDLWindow::AddSnake(){
    
}

//affichage du score 
void MainSDLWindow::score(){

    TTF_Font* font = NULL;
    font = TTF_OpenFont("Fonts/Arial/Arial.ttf", 12);
    
	SDL_Color couleur = {255, 255, 255};
	SDL_Surface* texte = TTF_RenderText_Blended(font, "test", couleur) ;

	SDL_FreeSurface(texte); 
	TTF_CloseFont(font);
    
};

//Quit the game
void MainSDLWindow::CheckForQuit(){
    SDL_Event event;
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            IsGameRunning = false;
            TTF_Quit();
        }
    }
}


SDL_Renderer *MainSDLWindow::GetRenderer(){return renderer;}
bool MainSDLWindow::GetGameState(){return IsGameRunning;}
int MainSDLWindow::GetFrameRate(){return frame_rate;}
SDL_Rect MainSDLWindow::GetSnake(){return head;}

void MainSDLWindow::SetSnake(SDL_Rect snake){head = snake;}

