#include "playground.hpp"

Snake::Snake(){
    this->length = this->turn =  1;
    this->direction = this->newDirection = this->score = this->count = 0;
    this->IsGameWon = false;

    this->head = new Segment();

    this->head->SetX(SQUARES / 2 * PIXELS - PIXELS);
    this->head->SetY(this->GetX());
    this->head->Init(direction, this->GetX(), this->GetY());
    this->tail = head;
    this->startCol = NULL;

    this->fruit = new Fruit();
    this->fruit->GenerateFruitCoord(head, fruit);

    for (int i = 0; i < SET; i++)
    {
        this->ballStars[i] = false;
    }
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
        cout << "Segment: " << position + 1 << "\n";
        cout << "X:" << body->GetX() / PIXELS << ", ";
        cout << "Y:" << body->GetY() / PIXELS << "\n\n";
        body = body->GetNext();
        position++;
    } while (body != NULL);
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
    this->length = this->turn =  1;
    this->direction = this->newDirection = this->score = this->count = 0;
    this->IsGameWon = false;

    for (int i = 0; i < SET; i++)
    {
        ballStars[i] = false;
    }
    
    head->ResetBody();
    head->SetX(SCREEN_SIZE / 2 - PIXELS);
    head->SetY(head->GetX());

    startCol = NULL;
    tail = head;
    fruit->ResetFruits();
    fruit->GenerateFruitCoord(head, fruit);

    UpdateCoords();
}

// Agrandie le serpent
void Snake::Eat(){
    score += SCORE_TO_ADD * turn;
    length += 1;
    count += 1;
    if (count % SET) { turn += 1; }

    ballStars[fruit->GetStar()] = true;
    
    tail = tail->AddSnake(this->direction, tail->GetX(), tail->GetY());
    if (length == 5) { startCol = tail; }
    UpdateCoords();
}

void Snake::CheckFruit(){
    if (head->GetX() / PIXELS == fruit->GetX() && head->GetY() / PIXELS == fruit->GetY())
    {
        Eat();
        fruit->GenerateFruitCoord(head, fruit);
        

        Fruit *temp = fruit;
        while (temp->CheckNext())
        {
            temp = temp->GetNext();
        }
        temp->GenerateFruit();
        temp = temp->GetNext();
        temp->SetMalus();
        temp->GenerateFruitCoord(head, fruit);
    }

    Fruit *malusFruits = fruit->GetNext();
    while (malusFruits != NULL)
    {
        if (head->GetX() / PIXELS == malusFruits->GetX() && head->GetY() / PIXELS == malusFruits->GetY())
        {
            Reset();
        }
        malusFruits = malusFruits->GetNext();
    }
}

Segment *Snake::GetHead(){return head;}
Fruit *Snake::GetFruit(){return fruit;}
int Snake::GetScore(){return score;}
int Snake::GetLength(){return length;}
int Snake::GetTurn(){return turn;};
int Snake::GetX(){return head->GetX();}
int Snake::GetY(){return head->GetY();}
bool *Snake::GetBallStars(){return ballStars;}