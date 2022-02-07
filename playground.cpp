#include "playground.hpp"
#include "snake.hpp"

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
    this->headText = this->ballText = this->bodyText = this->tailText = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(headText);
    SDL_DestroyTexture(bodyText);
    SDL_DestroyTexture(tailText);
    SDL_DestroyTexture(ballText);
}

int MainSDLWindow::Init(){
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
    return EXIT_FAILURE;
  }
    //Création de la fenêtre
    window = SDL_CreateWindow("Snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_SIZE, SCREEN_SIZE, SDL_WINDOW_RESIZABLE);
    if (window == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    
    //Création du renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Surface *head, *body, *tail, *ball = NULL; 
    head = SDL_LoadBMP("textures/head.bmp");
    if(head == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    headText = SDL_CreateTextureFromSurface(renderer, head);
    if(headText == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_FreeSurface(ball);

    body = SDL_LoadBMP("textures/body.bmp");
    if(head == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    bodyText = SDL_CreateTextureFromSurface(renderer, body);
    if(bodyText == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_FreeSurface(ball);

    tail = SDL_LoadBMP("textures/tail.bmp");
    if(head == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    tailText = SDL_CreateTextureFromSurface(renderer, tail);
    if(headText == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_FreeSurface(ball);

    ball = SDL_LoadBMP("textures/ball.bmp");
    if(head == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    ballText = SDL_CreateTextureFromSurface(renderer, ball);
    if(ballText == NULL)
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s", SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_FreeSurface(ball);

    return EXIT_SUCCESS;
}


//Draw the playground
void MainSDLWindow::Draw(Segment *head, Fruit *fruit, int score){
    int angle = 0;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 75, 75, 75, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &map);
    
    square.x = fruit->GetX() * PIXELS;
    square.y = fruit->GetY() * PIXELS;
    SDL_SetRenderTarget(renderer, ballText); 
    SDL_RenderCopy(renderer, ballText, NULL, &square);

    switch (head->GetDirection())
    {
    case UP:
        angle = 180;
        break;
    case RIGHT:
        angle = -90;
        break;
    case LEFT:
        angle = 90;
        break;
    case DOWN:
        angle = 0;
        break;
    case PAUSE:
        angle = 0;
        break;
    default:
        break;
    }

    square.x = head->GetX();
    square.y = head->GetY();
    SDL_SetRenderTarget(renderer, headText); 
    SDL_RenderCopyEx(renderer, headText, NULL, &square, angle, NULL, SDL_FLIP_NONE);

    Segment *body;
    body = head;

    while (body->CheckNext())
    {
        body = body->GetNext();
        square.x = body->GetX();
        square.y = body->GetY();
        SDL_SetRenderTarget(renderer, bodyText);
        if (body->GetDirection() == LEFT || body->GetDirection() == RIGHT)
        {
            angle = 90;
        }else{angle = 0;}
        
        SDL_RenderCopyEx(renderer, bodyText, NULL, &square, angle, NULL, SDL_FLIP_NONE);
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