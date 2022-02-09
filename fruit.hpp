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
    void ResetFruits();

    bool CheckNext();

    bool GetMalus();
    int GetX();
    int GetY();
    int GetStar();
    Fruit *GetNext();

    void SetMalus();

private:
    int x,y;
    int star;
    bool malus;
    Fruit *next;
};