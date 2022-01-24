#include "exercice3.hpp"

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
    window = SDL_CreateWindow("Une fenêtre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_RESIZABLE);
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
    //Création du rectangle
    rect.x = width/2;
    rect.y = height/2;
    rect.w = 16;
    rect.h = 16;

    return EXIT_SUCCESS;
}
SDL_Renderer *MainSDLWindow::GetRenderer(){return renderer;}
SDL_Rect MainSDLWindow::GetRect(){return rect;}


int main()
{
    bool IsGameRunning = true;

    MainSDLWindow main_window;
    main_window.Init("Manipulation de la SDL2", 600, 600);
    
    SDL_Renderer* renderer = main_window.GetRenderer();
    SDL_Rect rect = main_window.GetRect();

    while (IsGameRunning){
        const int speed = 5;

        Uint32 frame_time_start = SDL_GetTicks();
        SDL_Event event;
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                IsGameRunning = false;
            }
        }
        
        //Déplacement du rect
        if (keystates[SDL_SCANCODE_UP]) {
            rect.y -= speed;
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            rect.y += speed;
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            rect.x -= speed;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            rect.x += speed;
        }

        //Clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); //Change la couleur de fond
        SDL_RenderClear(renderer);

        //Draw a white simple rectangle
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &rect);
        
        //Render the rectangle
        SDL_RenderPresent(renderer);

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if(frame_time_interval < frame_rate){
            SDL_Delay(frame_rate-frame_time_interval);
        }
    }
}