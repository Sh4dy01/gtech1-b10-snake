#pragma once

#include <SDL2/SDL.h>

class Segment {
public:
    Segment();
    ~Segment();
    void AddSnake(int direction, int speed);
    void Move();
    void Init(int direction, int speed);

    int GetX();
    int GetY();
    void SetX(int newx);
    void SetY(int newy);
    void SetDirection(int nextDirection);
    void ResetBody();
private:
    Segment *next;
    
    int direction, nextDirection;
    int speed;
    int x, y;
};


class Snake {
public:
    Snake();
    ~Snake();

    void Init(int squares, int pixels);
    void CheckDirection();
    void CheckBorders();
    void Move();
    void Eat();
    void Reset();

    int GetDirection();
    int GetX();
    int GetY();
    int GetLength();
    void SetTail(Segment *tail);

private:
    Segment* head;
    Segment* tail;

    int length;
    int direction, newDirection;
    int speed;
    int playgroundLength, pixels;
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