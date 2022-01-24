#include "renderer.cpp"

int main()
{
    bool IsGameRunning = true;

    MainSDLWindow main_window;
    main_window.Init("Snake", 640, 640);
    
    SDL_Renderer* renderer = main_window.GetRenderer();

    do{

        Uint32 frame_time_start = SDL_GetTicks();
        SDL_Event event;

        const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        while(SDL_PollEvent(&event)){
            if(event.type == SDL_QUIT){
                IsGameRunning = false;
            }
        }
        
        //Déplacement du rect

        //Clear
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE); //Change la couleur de fond
        SDL_RenderClear(renderer);

        //Draw a white simple rectangle
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        
        //Render the rectangle
        SDL_RenderPresent(renderer);

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if(frame_time_interval < frame_rate){
            SDL_Delay(frame_rate-frame_time_interval);
        }
    }while(IsGameRunning);
}