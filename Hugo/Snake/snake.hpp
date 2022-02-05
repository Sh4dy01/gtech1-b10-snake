#pragma once

#include <bits/stdc++.h>
#include <cstdlib>

#define SQUARES 20
#define ARRAY_SIZE (SQUARES-2)*(SQUARES-2)

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


class Snake {
public:
    Snake();
    ~Snake();

    void Move();
    void Eat();
    void CheckDirection();
    bool CheckBorders();
    void CheckCollision();
    void UpdateCoords();
    void PrintCoords();
    void Reset();

    int GetX();
    int GetY();
    Segment *GetHead();

private:
    Segment *head;
    Segment *tail;

    int length;
    int direction, newDirection;
    int coords[ARRAY_SIZE][2];
};


class Fruit{
public:
    Fruit();
    
    void GenerateFruit();

    int GetX();
    int GetY();

private:
    int x,y;
};