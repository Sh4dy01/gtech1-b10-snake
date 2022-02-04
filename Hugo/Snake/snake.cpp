#include "snake.hpp"
#include <cstdlib>

Snake::Snake(){
    this->length = 1;
    this->direction = 0;
    this->newDirection = 0;
    this->speed = 4;
    head = new Segment;
}

Snake::~Snake(){
    if (head != NULL)
    {
        delete head;
    }
}

void Snake::Init(int squares, int pixels){
    this->playgroundLength = squares;
    this->pixels = pixels;
    this->head->SetX(playgroundLength * pixels / 2 - pixels);
    this->head->SetY(this->GetX());
    this->head->Init(direction, speed, this->GetX(), this->GetY());
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

    if (head->GetX()%32==0 && head->GetY()%32==0)
    {
        direction = newDirection;
        head->SetDirection(direction);
    }
}


void Snake::Move(){
    head->Move();
}

void Snake::CheckBorders(){
    if (head->GetX() > playgroundLength * pixels - pixels * 2)
    {
        Reset();
    }
    else if (head->GetX() < 0 + pixels)
    {
        Reset();
    }
    else if (head->GetY() > playgroundLength * pixels - pixels * 2)
    {
        Reset();
    }
    else if (head->GetY() < 0 + pixels)
    {
        Reset();
    }
}

void Snake::Reset(){
    head->SetX(playgroundLength * pixels / 2 - pixels);
    head->SetY(head->GetX());

    length = 1;
    direction = 0;
    newDirection = 0;
    head->ResetBody();
}

void Snake::Eat(){
    if (head != NULL)
    {
        head->AddSnake(this->direction, this->speed, this->GetX(), this->GetY());
        length+=1;
    }
}

Segment* Snake::GetHead(){return head;}
int Snake::GetDirection(){return direction;}
int Snake::GetX(){return head->GetX();}
int Snake::GetY(){return head->GetY();}
int Snake::GetLength(){return length;}

void Snake::SetTail(Segment *tail){this->tail = tail;}

Segment::Segment(){
    this->direction, this->speed = 0;
    this->x, this->y = 0;
    this->direction, this->nextDirection = 0;
    this->next = NULL;
}

Segment::~Segment(){

    if (next != NULL)
    {
        delete next;
    }
}

void Segment::Init(int direction, int speed, int x, int y){
    this->direction = direction;
    this->speed = speed;
    this->x = x;
    this->y = y;

    switch (direction)
    {
    case 1:
        this->y += 32;
        break;
    case 2:
        this->y -= 32;
        break;
    case 3:
        this->x += 32;
        break;
    case 4:
        this->x -= 32;
        break;
    default:
        break;
    }
    cout << "x:" << this->GetX() << "y:" << this->GetY() << "\n";
}

void Segment::AddSnake(int direction, int speed, int x, int y){
    if (next != NULL)
    {
        next->AddSnake(this->direction, speed, this->x, this->y);
    }else{
        Segment *temp = new Segment;
        next = temp;
        next->Init(direction, speed, x, y);
    }
}

void Segment::Move(){
    if (this->x%32==0 && this->y%32==0)
    {
        this->direction = this->nextDirection;
    }

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

    if (next != NULL)
    {
        next->Move();
    }
}

void Segment::SetDirection(int nextDirection){

    this->nextDirection = nextDirection;
    if (next != NULL)
    {
        next->SetDirection(direction);
    }
}

void Segment::ResetBody(){
    if (next != NULL)
    {
        delete next;
    }
}

Segment* Segment::CheckNext(int length, int count){
    while (count != length)
    {
        count++;
        if (this->next != NULL)
        {
            next->CheckNext(length, count);
        }
    }

    return this;
}

int Segment::GetX(){return x;}
int Segment::GetY(){return y;}
void Segment::SetX(int newx){this->x = newx;}
void Segment::SetY(int newy){this->y = newy;}


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