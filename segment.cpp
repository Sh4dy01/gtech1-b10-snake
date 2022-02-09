#include "segment.hpp"

Segment::Segment(){
    this->direction;
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

void Segment::Init(int direction, int x, int y){
    this->direction = direction;
    this->x = x;
    this->y = y;

    switch (direction)
    {
    case UP:
        this->y += PIXELS;
        break;
    case DOWN:
        this->y -= PIXELS;
        break;
    case RIGHT:
        this->x -= PIXELS;
        break;
    case LEFT:
        this->x += PIXELS;
        break;
    default:
        break;
    }
}

Segment *Segment::AddSnake(int direction, int x, int y){
    Segment *temp = new Segment();
    next = temp;
    next->Init(this->direction, this->x, this->y);

    return next;
}

void Segment::Move(){
    if (this->x % PIXELS == 0 && this->y % PIXELS == 0)
    {
        this->direction = this->nextDirection;
    }

    switch (direction)
    {
    case UP:
        this->y -= SPEED;
        break;
    case DOWN:
        this->y += SPEED;
        break;
    case RIGHT:
        this->x += SPEED;
        break;
    case LEFT:
        this->x -= SPEED;
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
    this->next = NULL;
}

bool Segment::CheckNext(){return (next != NULL) ? true : false;}

int Segment::GetX(){return x;}
int Segment::GetY(){return y;}
Segment *Segment::GetNext(){return next;}
int Segment::GetDirection(){return direction;}

void Segment::SetX(int newx){this->x = newx;}
void Segment::SetY(int newy){this->y = newy;}