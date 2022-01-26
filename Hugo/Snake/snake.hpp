#pragma once

#include <SDL2/SDL.h>

class Snake {
public:
    void Move(int dir);
    void Eat();
    void Print();
private:
    Segment* head;
    int speed;
};

class Segment {
private:
    Segment *next;
};

class Fruit{
public:
    Fruit();

    int *GenerateFruit();
private:
    int pos[2];
};