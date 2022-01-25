#include "playground.cpp"

int main()
{
    MainSDLWindow main_window;
    main_window.Init();
    int frame_rate = main_window.GetFrameRate();
    SDL_Renderer* renderer = main_window.GetRenderer();

    do{
        Uint32 frame_time_start = SDL_GetTicks();

        main_window.CheckForQuit(); //Click X to quit the game
        main_window.DrawPlayground(); //Draw the playground
        
        SDL_RenderPresent(renderer); //Refresh the renderer

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if(frame_time_interval < frame_rate){
            SDL_Delay(frame_rate-frame_time_interval);
        }
    }while(main_window.GetGameState());
}