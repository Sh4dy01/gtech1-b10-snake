#include "snake.hpp"
#include "playground.hpp"

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

Snake::Snake(){
    this->length = 1;
    this->direction, this->newDirection = 0;

    head = new Segment();
    this->head->SetX(SCREEN_SIZE / 2 - PIXELS);
    this->head->SetY(this->GetX());
    this->head->Init(direction, this->GetX(), this->GetY());
    this->tail = head;
}

Snake::~Snake(){
    delete head;
}

// Change la direction du snake si appuie d'une des flèches directionnelles
void Snake::CheckDirection(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP]){
        newDirection = UP;
    }
    else if (keystates[SDL_SCANCODE_DOWN]){
        newDirection = DOWN;
    }
    else if (keystates[SDL_SCANCODE_LEFT]){
        newDirection = LEFT;
    }
    else if (keystates[SDL_SCANCODE_RIGHT]){
        newDirection = RIGHT;
    }


    if (head->GetX() % PIXELS == 0 && head->GetY() % PIXELS == 0)
    {
        if (direction != -newDirection){direction = newDirection;}
        head->SetDirection(direction);
    }
}

void Snake::Move(){
    CheckDirection();

    head->Move();

    UpdateCoords();
}

// Met à jour les coordonnées de chaque partie du segment
void Snake::UpdateCoords(){
    Segment *body = head;
    int position = 0;

    do{
        coords[position][0] = body->GetX() / PIXELS;
        coords[position][1] = body->GetY() / PIXELS;
        body = body->GetNext(); //fin d'itération
        position++;
    } while (body != NULL);
}

// Affiche les coordonnées de chaque partie du serpent
void Snake::PrintCoords(){
    for (int i = 0; i < length; i++)
    {
        cout << "i:" << i << "\n";
        cout << "X:" << coords[i][0] << ", ";
        cout << "Y:" << coords[i][1] << "\n\n";
    }
}

// Vérifie si la tête touche une des bordures de la zone de jeu et recommence la partie à zero.
bool Snake::CheckBorders(){
    if (head->GetX() > SCREEN_SIZE - PIXELS * 2)
    {
        Reset();
        return true;
    }
    else if (head->GetX() < 0 + PIXELS)
    {
        Reset();
        return true;
    }
    else if (head->GetY() > SCREEN_SIZE - PIXELS * 2)
    {
        Reset();
        return true;
    }
    else if (head->GetY() < 0 + PIXELS)
    {
        Reset();
        return true;
    }

    return false;
}

void Snake::CheckCollision(){
    if (length > 3){
        Segment *body = head->GetNext();

        if (head->GetX() == body->GetX() && head->GetY() == body->GetY()){
            /* code */
        }
    }
}

// Restaure les variables par défaut
void Snake::Reset(){
    length = 1;
    direction = 0;
    newDirection = 0;

    head->ResetBody();
    head->SetX(SCREEN_SIZE / 2 - PIXELS);
    head->SetY(head->GetX());
    tail=head;
    
    for (int i = 0; i < length; i++)
    {
        coords[i][0] = 0;
        coords[i][1] = 0;
    }
}

// Agrandie le serpent
void Snake::Eat(){
    if (head != NULL)
    {
        tail = tail->AddSnake(this->direction, this->GetX(), this->GetY());
        length+=1;
    }
}

Segment* Snake::GetHead(){return head;}
int Snake::GetX(){return head->GetX();}
int Snake::GetY(){return head->GetY();}


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
        this->next->SetDirection(direction);
    }
}

void Segment::ResetBody(){
    if (next != NULL)
    {
        delete next;
    }
    next = NULL;
}

bool Segment::CheckNext(){return (next != NULL) ? true : false;}

int Segment::GetX(){return x;}
int Segment::GetY(){return y;}
Segment *Segment::GetNext(){return next;}

void Segment::SetX(int newx){this->x = newx;}
void Segment::SetY(int newy){this->y = newy;}


Fruit::Fruit(){
    this->x = 0;
    this->y = 0;

    this->GenerateFruit();
}

void Fruit::GenerateFruit(){
    x = rand() % (SQUARES-2) + 1;
    y = rand() % (SQUARES-2) + 1;
}

int Fruit::GetX(){return x;}
int Fruit::GetY(){return y;}