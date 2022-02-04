#include "snake.hpp"
#include <cstdlib>

Snake::Snake(){
    this->direction = 0;
    this->x,y = 0;
}

void Snake::CheckDirection(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP] && direction != 2){
        direction = 1;
    }
    else if (keystates[SDL_SCANCODE_DOWN] && direction != 1){
        direction = 2;
    }
    else if (keystates[SDL_SCANCODE_LEFT] && direction != 4){
        direction = 3;
    }
    else if (keystates[SDL_SCANCODE_RIGHT] && direction != 3){
        direction = 4;
    }
}

void Snake::Move(int newx, int newy){
    this-> x = newx;
    this-> y = newy;
}

Fruit::Fruit(){
    this->pos[0] = 0;
    this->pos[1] = 0;
}

int *Fruit::GenerateFruit(){
    pos[0] = rand() % 19 + 1;
    pos[1] = rand() % 19 + 1;

    return pos;
}