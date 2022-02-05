#include "playground.cpp"
#include "snake.cpp"

int main()
{
    srand (time(NULL)); //New seed for generating random numbers
    
    Uint32 frame_start;
    int frame_delay;

    MainSDLWindow main_window;
    Snake snake;

    main_window.Init();
    SDL_Renderer* renderer = main_window.GetRenderer();

    do{
        frame_start = SDL_GetTicks();

        main_window.CheckForQuit(); //Click X to quit the game
        snake.Move();
        if(snake.CheckBorders()) {main_window.GenerateFruit();}
        if(main_window.CheckFruit()) {snake.Eat();}
        
        main_window.Draw(snake.GetHead()); //Draw everything

        frame_delay = FRAME_RATE - (SDL_GetTicks() - frame_start);
        if (frame_delay > 0) {SDL_Delay(frame_delay);}
        
    }while(main_window.GetGameState());
}