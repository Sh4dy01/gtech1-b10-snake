#pragma once

#include <SDL2/SDL.h>

class Segment {
public:
    Segment();
    ~Segment();
    void AddSnake();
    void Move(int newx, int newy);
private:
    Segment *next;
    
    int x, y;
};


class Snake {
public:
    Snake();
    ~Snake();

    void Init(int pixels, int squares);
    void CheckDirection();
    void CheckBorders();
    void Move();
    void Eat();
    void Print();
    void Reset();

    int GetDirection();
    int GetX();
    int GetY();
    int GetLength();

private:
    Segment* head;
    Segment* tail;

    int length;
    int direction, newDirection;
    int x;
    int y;
    int speed;
    int pixels, squares;
};


class Fruit{
public:
    Fruit();
    ~Fruit();

    void GenerateFruit();

    int GetX();
    int GetY();

private:
    int x,y;
};