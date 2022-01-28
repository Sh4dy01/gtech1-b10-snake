#include "playground.cpp"
#include "snake.cpp"

int main()
{
    MainSDLWindow main_window;
    Snake snake;
    
    main_window.Init();
    snake.Init(main_window.GetPixels(), main_window.GetSquares());
    
    int frame_rate = main_window.GetFrameRate();
    SDL_Renderer* renderer = main_window.GetRenderer();

    do{
        Uint32 frame_time_start = SDL_GetTicks();

        main_window.CheckForQuit(); //Click X to quit the game
        snake.CheckDirection();
        snake.Move();
        
        main_window.Draw(snake.GetX(), snake.GetY()); //Draw everything

        Uint32 frame_time_interval = SDL_GetTicks() - frame_time_start;
        if(frame_time_interval < frame_rate){
            SDL_Delay(frame_rate-frame_time_interval);
        }
    }while(main_window.GetGameState());
}