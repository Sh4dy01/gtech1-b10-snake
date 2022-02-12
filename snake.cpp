#include "snake.hpp"

Snake::Snake(){
    this->length = this->turn =  this->difficultyLevel =  1;
    this->direction = this->newDirection = this->score = 0;

    this->head = new Segment();

    this->head->SetX(SQUARES / 2 * PIXELS - PIXELS);
    this->head->SetY(this->GetX());
    this->head->Init(direction, this->GetX(), this->GetY());
    this->tail = head;
    this->startCol = NULL;

    this->fruit = new Fruit();
    this->fruit->GenerateFruitCoord(head, fruit, rand() % SET);

    ResetBallCollection();
}

Snake::~Snake(){
    delete head, fruit, tail, startCol;
}

// Change the head's direction if the arrows are pressed
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
    }/*
    else if (keystates[SDL_SCANCODE_SPACE]){
        newDirection = PAUSE;
    }*/

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
        CheckBodyCollision();
        CheckBordersCollision();
        CheckFruitCollision();
    }
}

// Update every segment's coords
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

// Check if the head touched the borders
void Snake::CheckBordersCollision(){
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

// Check if the head touched his body
void Snake::CheckBodyCollision(){
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

// Add a segment after the tail
void Snake::Eat(){
    length += 1;
    score += SCORE_TO_ADD * difficultyLevel;

    ballCollection[fruit->GetStar()-1] = true;

    canWin = true;
    for (int i = 0; i < SET; i++)
    {
        if (ballCollection[i] == false)
        {
            canWin = false;
        }
    }
    
    tail = tail->AddSnake(this->direction, tail->GetX(), tail->GetY());
    if (length == 5) { startCol = tail; }
    UpdateCoords();
}

// Check if the head hurt a fruit
void Snake::CheckFruitCollision(){
    if ((head->GetX() / PIXELS == fruit->GetX() && head->GetY() / PIXELS == fruit->GetY()) && !canWin)
    {
        // Generate a dragon ball
        Eat();
        if (!canWin)
        {
            int star = rand() % SET;
            do
            {
                star = rand() % SET;
                cout << star << endl;
            } while (ballCollection[star]);

            fruit->GenerateFruitCoord(head, fruit, star);
        }
        
        // Generate different malus balls
        for (int i = 0; i < difficultyLevel; i++)
        {
            int star = 0;

            Fruit *temp = fruit;
            while (temp->CheckNext())
            {
                temp = temp->GetNext();
            }
            temp->GenerateFruit();
            temp = temp->GetNext();

            if (canWin && i+1 == difficultyLevel)
            {
                temp->SetWinnable();
            } else { temp->SetMalus(); }
            
            temp->GenerateFruitCoord(head, fruit, star);
        }
    }
    
   
    // Check collision between all other balls
    Fruit *allFruits = fruit->GetNext();
    while (allFruits != NULL)
    {
        if (head->GetX() / PIXELS == allFruits->GetX() && head->GetY() / PIXELS == allFruits->GetY())
        {
            if (allFruits->CheckIfMalus())
            {
                Reset();
                break;
            } else if (allFruits->CheckIfWin())
            {
                fruit->ResetFruits();
                canWin = false;
                difficultyLevel++;
                ResetBallCollection();
                break;
            }       
        }
        allFruits = allFruits->GetNext();
    }
}

// Reset the variables
void Snake::Reset(){
    srand(time(NULL));
    
    this->length = this->turn =  this->difficultyLevel =  1;
    this->direction = this->newDirection = this->score = 0;
    
    head->ResetBody();
    head->SetX(SCREEN_SIZE / 2 - PIXELS);
    head->SetY(head->GetX());

    startCol = NULL;
    tail = head;
    fruit->ResetFruits();
    fruit->GenerateFruitCoord(head, fruit, rand() % SET);

    ResetBallCollection();

    UpdateCoords();
}

void Snake::ResetBallCollection(){
    for (int i = 0; i < SET; i++)
    {
        ballCollection[i] = false;
    }
    canWin = false;
}

Segment *Snake::GetHead(){return head;}
Fruit *Snake::GetFruit(){return fruit;}
int Snake::GetScore(){return score;}
int Snake::GetLength(){return length;}
int Snake::GetX(){return head->GetX();}
int Snake::GetY(){return head->GetY();}
int Snake::GetLevel(){return difficultyLevel;}
bool Snake::CheckIfCanWin(){return canWin;}
bool *Snake::GetBallStars(){return ballCollection;}