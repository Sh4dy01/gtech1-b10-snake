#include "playground.hpp"

MainSDLWindow::MainSDLWindow(){
    this->window,renderer = NULL;
    scoreText = "SCORE : 0";
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
    SDL_FreeSurface(scoreSurface);
    SDL_DestroyTexture(scoreTexture);
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
    if(TTF_Init() == -1){
    cout << "Erreur d'initialisation de Font :" << TTF_GetError();
    return EXIT_FAILURE;
    };

    font = TTF_OpenFont("ARIAL.TTF", 50);

	couleurScore = {255, 255, 255};
	scoreSurface = TTF_RenderText_Solid(font, scoreText, couleurScore) ;

    if(scoreSurface == NULL){
        cout << "Erreur de rendu :" << TTF_GetError();
        return EXIT_FAILURE;
    }

    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);

    SDL_Rect score_area;
    score_area.x = 0;
    score_area.y = 0;
    score_area.w = scoreSurface->w;
    score_area.h = scoreSurface->h;

    return EXIT_SUCCESS;
}


//Draw the playground
void MainSDLWindow::Draw(int score){
    string s = to_string(score);
    scoreText = s.str();
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    scoreSurface = TTF_RenderText_Solid(font, scoreText, couleurScore);
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreArea);
    SDL_RenderPresent(renderer);
}


//affichage du score 
void MainSDLWindow::score(){



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

