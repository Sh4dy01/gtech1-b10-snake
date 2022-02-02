#include "playground.cpp"
#include "snake.cpp"

int main()
{
    srand (time(NULL));
    Uint32 frame_start;
    int frame_delay;
    int frame_rate = 20;

    MainSDLWindow main_window;
    Snake snake;

    main_window.Init();
    snake.Init(main_window.GetSquares(), main_window.GetPixels());

    SDL_Renderer* renderer = main_window.GetRenderer();

    do{
        frame_start = SDL_GetTicks();

        main_window.CheckForQuit(); //Click X to quit the game
        snake.CheckDirection();
        snake.CheckBorders();
        if(main_window.CheckFruit()) {/*snake.Eat();*/}
        snake.Move();
        
        main_window.Draw(snake.GetX(), snake.GetY(), snake.GetLength()); //Draw everything

        frame_delay = frame_rate - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0) {SDL_Delay(frame_delay);}
    }while(main_window.GetGameState());
}