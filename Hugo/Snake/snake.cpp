#include "snake.hpp"
#include <cstdlib>

Snake::Snake(){
    this->x, y = 0;
    this->direction = 0;
    this->newDirection = 0;
    this->speed = 2;
}

Snake::~Snake(){
    if (head != NULL)
    {
        delete head;
    }
}

void Snake::CheckDirection(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP] && direction != 2){
        newDirection = 1;
    }
    else if (keystates[SDL_SCANCODE_DOWN] && direction != 1){
        newDirection = 2;
    }
    else if (keystates[SDL_SCANCODE_LEFT] && direction != 4){
        newDirection = 3;
    }
    else if (keystates[SDL_SCANCODE_RIGHT] && direction != 3){
        newDirection = 4;
    }
}

void Snake::Move(){
    switch (direction)
    {
    case 1:
        this-> y -= speed;
        break;
    case 2:
        this-> y += speed;
        break;
    case 3:
        this-> x -= speed;
        break;
    case 4:
        this-> x += speed;
        break;
    default:
        break;
    }
}

void Snake::Eat(){
    if (head != NULL)
    {
        head->AddSnake();
    }
}

int Snake::GetDirection(){return direction;}
int Snake::GetX(){return x;}
int Snake::GetY(){return y;}

Segment::Segment(){
    this->x, y = 0;
}

Segment::~Segment(){
    if (next != NULL)
    {
        delete next;
    }
}

void Segment::AddSnake(){
    if (next != NULL)
    {
        next->AddSnake();
    }else{
        Segment *temp;
        next = temp;
    }
}

void Segment::Move(int newx, int newy){
    this->x = newx;
    this->y = newy;
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