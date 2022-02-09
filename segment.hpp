#pragma once

#include <iostream>

#include "constants.hpp"

class Segment {
public:
    Segment();
    ~Segment();

    void Init(int direction, int x, int y);
    void Move();
    Segment *AddSnake(int direction, int x, int y);
    void ResetBody();

    bool CheckNext();
    Segment *GetNext();
    int GetDirection();
    int GetX();
    int GetY();

    void SetX(int newx);
    void SetY(int newy);
    void SetDirection(int nextDirection);

private:
    Segment *next;
    
    int direction, nextDirection;
    int x, y;
};