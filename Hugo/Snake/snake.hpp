#pragma once

#include <bits/stdc++.h>
#include <cstdlib>

#define SQUARES 6
#define ARRAY_SIZE ((SQUARES-2)*(SQUARES-2))
#define SCORE_TO_ADD 10
#define SPEED 2

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2
#define PAUSE 0


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

class Fruit{
public:
    Fruit();
    
    void GenerateFruit();
    void GenerateFruit(int exclude[][2], int length);

    int GetX();
    int GetY();

private:
    int x,y;
};


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
    Segment *GetHead();
    Fruit *GetFruit();

private:
    Segment *head;
    Segment *startCol;
    Segment *tail;
    Fruit *fruit;

    int length;
    int direction, newDirection;
    int coords[ARRAY_SIZE][2];
    int score;
};