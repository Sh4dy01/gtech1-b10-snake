#include "playground.hpp"
#include "snake.hpp"

int main()
{
    srand(time(NULL));

    Uint32 frame_start;
    int frame_delay;

    MainSDLWindow main_window;
    Snake snake;

    main_window.Init();
    SDL_Renderer* renderer = main_window.GetRenderer();

    do{
        frame_start = SDL_GetTicks();

        main_window.CheckForQuit();
        snake.Move();
        main_window.Draw(snake.GetHead(), snake.GetFruit(), snake.GetBallStars(), snake.GetLength(), snake.GetScore(), snake.GetLevel(), snake.CheckIfCanWin()); //Draw everything

        frame_delay = FRAME_RATE - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0) {SDL_Delay(frame_delay);}
        
    }while(main_window.GetGameState());
}