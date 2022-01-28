#pragma once

#include <SDL2/SDL.h>

class Segment {
public:
    Segment();
    ~Segment();
    void AddSnake(int newx, int newy);
    void Move();
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
    void Move();
    void Eat();
    void Print();

    int GetDirection();
    int GetX();
    int GetY();
private:
    Segment* head;

    int direction;
    int newDirection;
    float x, y;
    int speed;
};





class Fruit{
public:
    Fruit();

    int *GenerateFruit();
private:
    int pos[2];
};