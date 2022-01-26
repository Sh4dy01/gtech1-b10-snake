#include "snake.hpp"
#include <SDL2/SDL.h>

Snake::Snake(){
    this->dir = 0;
    this->speed =1;
}

void Snake::ChangeDir(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
       dir = 1;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        dir = 2;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        dir = 3;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        dir = 4;
    }
}

void Snake::Move(){
    switch (dir)
    {
    case 1:
        snake.x += speed;
        break;

     case 2:
        snake.x -= speed;
        break;

     case 3:
        snake.y -= speed;
        break;

     case 4:
        snake.y += speed;
        break;
    
    default:
        break;
    }
}

SDL_Rect Snake::GetHead(){return snake;}
