#pragma once

#include <iostream>

#include "constants.hpp"
#include "segment.hpp"
#include "fruit.hpp"

class Snake {
public:
    Snake();
    ~Snake();

    void Move();
    void Eat();
    void CheckDirection();
    void CheckBorders();
    void CheckCollision();
    void CheckFruit();
    void UpdateCoords();
    void Debug();
    void Reset();

    int GetX();
    int GetY();
    int GetScore();
    int GetLength();
    int GetBallCount();
    int GetTurn();
    bool *GetBallStars();
    Segment *GetHead();
    Fruit *GetFruit();

private:
    Segment *head;
    Segment *startCol;
    Segment *tail;
    Fruit *fruit;

    bool IsGameWon;
    bool ballStars[SET];
    int length, score, turn, count;
    int direction, newDirection;
};