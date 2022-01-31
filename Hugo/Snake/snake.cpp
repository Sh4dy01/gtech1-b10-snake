#include "snake.hpp"
#include <cstdlib>

MainSDLWindow window;

Snake::Snake(){
    this->x = 0;
    this->y = 0;
    this->length = 1;
    this->direction = 0;
    this->newDirection = 0;
    this->speed = 4;
}

Snake::~Snake(){
    if (head != NULL)
    {
        delete head;
    }
}

void Snake::Init(int pixels, int squares){
    this->pixels = pixels;
    this->squares = squares;
    this->x = this->pixels * this->squares / 2 - this->pixels;
    this->y = x;
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
    
    if (x%32==0 && y%32==0)
    {
        direction = newDirection;
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

void Snake::CheckBorders(){
    if (x > squares * pixels - pixels * 2)
    {
        Reset();
    }
    else if (x < 0 + pixels)
    {
        Reset();
    }
    else if (y > squares * pixels - pixels * 2)
    {
        Reset();
    }
    else if (y < 0 + pixels)
    {
        Reset();
    }
}

void Snake::Reset(){
    x = squares * pixels / 2 - pixels;
    y = x;
    direction = 0;
    newDirection = 0;
    length = 0;
}

void Snake::Print(){
    cout << x << "&" << y;
}

void Snake::Eat(){
    if (head != NULL)
    {
        head->AddSnake();
        length+=1;
    }
}

int Snake::GetDirection(){return direction;}
int Snake::GetX(){return x;}
int Snake::GetY(){return y;}
int Snake::GetLength(){return length;}

Segment::Segment(){
    this->x, y = 0;
    this->next = NULL;
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
    this->x = 0;
    this->y = 0;

    this->GenerateFruit();
}

void Fruit::GenerateFruit(){
    x = rand() % 18 + 1;
    y = rand() % 18 + 1;
}

int Fruit::GetX(){return x;}
int Fruit::GetY(){return y;}