#pragma once

#include <SDL2/SDL.h>

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
    void CheckBordersCollision();
    void CheckBodyCollision();
    void CheckFruitCollision();
    void UpdateCoords();
    void Reset();
    void ResetBallCollection();

    int GetX();
    int GetY();
    int GetScore();
    int GetLength();
    int GetLevel();
    bool *GetBallStars();
    bool CheckIfCanWin();
    Segment *GetHead();
    Fruit *GetFruit();

private:
    Segment *head;
    Segment *startCol;
    Segment *tail;
    Fruit *fruit;
    Fruit *last;

    bool CanWin, CanSpawnWinBall;
    bool ballCollection[SET];
    int length, score, turn, difficultyLevel;
    int direction, newDirection;
};