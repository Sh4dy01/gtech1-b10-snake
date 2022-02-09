#include "fruit.hpp"

Fruit::Fruit(){
    this->x = 0;
    this->y = 0;
    this->next = NULL;
    this->malus = false;
    this->win = false;
}

Fruit::~Fruit(){
    if (next != NULL)
    {
        delete next;
    }
}

Fruit *Fruit::GenerateFruit(){
    Fruit *temp = new Fruit();
    next = temp;

    return next;
}

void Fruit::GenerateFruitCoord(Segment *head, Fruit *fruit){
    int sameCoord = true;
    int tempX = GenerateRandomNumber();
    int tempY = GenerateRandomNumber();

    do 
    {
        sameCoord = true;
        Segment *body = head;
        do
        {
            if (tempX == body->GetX() / PIXELS && tempY == body->GetY() / PIXELS)
            {
                sameCoord = true;
                tempX = GenerateRandomNumber();
                tempY = GenerateRandomNumber();
                body = head;
            } else { sameCoord = false; }

            body = body->GetNext();
            
        } while (body != NULL);

        sameCoord = true;
        Fruit *fruits = fruit;
        do
        {
            if (tempX == fruits->GetX() && tempY == fruits->GetY())
            {
                sameCoord = true;
                tempX = GenerateRandomNumber();
                tempY = GenerateRandomNumber();
                fruits = fruit;     

            } else { sameCoord = false; }

            fruits = fruits->GetNext();
            
        } while (fruits != NULL);

        if (tempX == head->GetX() || tempY == head->GetY())
        {
            sameCoord = true;
            tempX = GenerateRandomNumber();
            tempY = GenerateRandomNumber();
        }
    } while (sameCoord);

    this->star = rand() % SET + 1;
    this->x = tempX;
    this->y = tempY;
}

int Fruit::GenerateRandomNumber(){
    int number = rand() % (SQUARES-2) + 1;

    return number;
}

void Fruit::ResetFruits(){
    if (next != NULL)
    {
        delete next;
    }
    this->next = NULL;
}

bool Fruit::CheckNext(){return (next != NULL) ? true : false;}

bool Fruit::CheckIfWin(){return win;}
bool Fruit::CheckIfMalus(){return malus;}
Fruit *Fruit::GetNext(){return next;}
int Fruit::GetX(){return x;}
int Fruit::GetY(){return y;}
int Fruit::GetStar(){return star;}

void Fruit::SetMalus(){malus = true;}
void Fruit::SetWinnable(){win = true;}