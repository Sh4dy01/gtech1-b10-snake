#include "snake.hpp"
#include "playground.hpp"

Snake::Snake(){
    this->length = 1;
    this->direction = this->newDirection = this->score = 0;

    head = new Segment();

    this->head->SetX(SQUARES / 2 * PIXELS - PIXELS);
    this->head->SetY(this->GetX());
    this->head->Init(direction, this->GetX(), this->GetY());
    this->tail = head;
    this->startCol = NULL;

    fruit = new Fruit();
}

Snake::~Snake(){
    delete head, fruit, tail, startCol;
}

// Change la direction du snake si appuie d'une des flèches directionnelles
void Snake::CheckDirection(){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (keystates[SDL_SCANCODE_UP] && direction != DOWN){
        newDirection = UP;
    }
    else if (keystates[SDL_SCANCODE_DOWN] && direction != UP){
        newDirection = DOWN;
    }
    else if (keystates[SDL_SCANCODE_LEFT] && direction != RIGHT){
        newDirection = LEFT;
    }
    else if (keystates[SDL_SCANCODE_RIGHT] && direction != LEFT){
        newDirection = RIGHT;
    }
    else if (keystates[SDL_SCANCODE_SPACE]){
        newDirection = PAUSE;
    }

    if (head->GetX() % PIXELS == 0 && head->GetY() % PIXELS == 0)
    {
        direction = newDirection;
        head->SetDirection(direction);
    }
}

void Snake::Move(){
    CheckDirection();
    if (direction != PAUSE)
    {
        head->Move();
        CheckCollision();
        CheckBorders();
        CheckFruit();
    }
}

// Met à jour les coordonnées de chaque partie du segment
void Snake::UpdateCoords(){
    Segment *body = head;
    int position = 0;

    do{
        coordsArray[position][0] = body->GetX() / PIXELS;
        coordsArray[position][1] = body->GetY() / PIXELS;
        body = body->GetNext(); //fin d'itération
        position++;
    } while (body != NULL);
    Debug();
}

// Affiche les coordonnées de chaque partie du serpent
void Snake::Debug(){
    for (int i = 0; i < length; i++)
    {
        cout << "Segment: " << i+1 << "\n";
        cout << "X:" << coordsArray[i][0] << ", ";
        cout << "Y:" << coordsArray[i][1] << "\n\n";
    }
}

// Vérifie si la tête touche une des bordures de la zone de jeu et recommence la partie à zero.
void Snake::CheckBorders(){
    if (head->GetX() > SCREEN_SIZE - PIXELS * 2)
    {
        Reset();
    }
    else if (head->GetX() < 0 + PIXELS)
    {
        Reset();
    }
    else if (head->GetY() > SCREEN_SIZE - PIXELS * 2)
    {
        Reset();
    }
    else if (head->GetY() < 0 + PIXELS)
    {
        Reset();
    }
}

void Snake::CheckCollision(){
    if (length > 4)
    {
        Segment *checkCol = startCol;
        do
        {
            if (head->GetX() == checkCol->GetX() && head->GetY() == checkCol->GetY()) 
            {
                Reset();
                break;
            }
            checkCol = checkCol->GetNext();
        }while (checkCol != NULL);
    }
}

// Restaure les variables par défaut
void Snake::Reset(){
    length = 1;
    direction = newDirection = score = 0;

    head->ResetBody();
    head->SetX(SCREEN_SIZE / 2 - PIXELS);
    head->SetY(head->GetX());

    startCol = NULL;
    tail = head;
    fruit->GenerateFruit();

    UpdateCoords();
}

// Agrandie le serpent
void Snake::Eat(){
    length += 1;
    tail = tail->AddSnake(this->direction, tail->GetX(), tail->GetY());
    if (length == 5)
    {
        startCol = tail;
    }
    UpdateCoords();
}

void Snake::CheckFruit(){
    if (head->GetX() / PIXELS == fruit->GetX() && head->GetY() / PIXELS == fruit->GetY())
    {
        score += SCORE_TO_ADD;
        Eat();
        fruit->GenerateFruit(head);
    }
}

Segment *Snake::GetHead(){return head;}
Fruit *Snake::GetFruit(){return fruit;}
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

void Segment::SetX(int newx){this->x = newx;}
void Segment::SetY(int newy){this->y = newy;}


Fruit::Fruit(){
    this->x = 0;
    this->y = 0;

    this->GenerateFruit();
}

void Fruit::GenerateFruit(){
    this->x = rand() % (SQUARES-2) + 1;
    this->y = rand() % (SQUARES-2) + 1;
}

void Fruit::GenerateFruit(Segment *head){
    int sameCoord = true;
    int tempX = rand() % (SQUARES-2) + 1;
    int tempY = rand() % (SQUARES-2) + 1;

    while (sameCoord == true)
    {
        Segment *body = head;
        do
        {
            if (tempX == body->GetX() / PIXELS && tempY == body->GetY() / PIXELS)
            {
                sameCoord = true;
                tempX = rand() % (SQUARES-2) + 1;
                tempY = rand() % (SQUARES-2) + 1;

                break;
            }else{sameCoord = false;}
            body = body->GetNext();
            
        } while (body != NULL);
    }

    this->x = tempX;
    this->y = tempY;

    cout << "Fruit: " << x << ", " << y << "\n";
}

int Fruit::GetX(){return x;}
int Fruit::GetY(){return y;}