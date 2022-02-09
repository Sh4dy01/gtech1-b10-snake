#pragma once

#include <iostream>

#include "constants.hpp"
#include "segment.hpp"

class Fruit{
public:
    Fruit();
    ~Fruit();

    Fruit *GenerateFruit();
    void GenerateFruitCoord(Segment *head, Fruit *fruit);
    int GenerateRandomNumber();
    void ResetFruits();

    bool CheckNext();

    bool CheckIfWin();
    bool CheckIfMalus();
    
    int GetX();
    int GetY();
    int GetStar();
    Fruit *GetNext();

    void SetMalus();
    void SetWinnable();

private:
    int x,y;
    int star;
    bool malus,win;
    Fruit *next;
};