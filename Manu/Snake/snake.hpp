#pragma once

//#include <SDL2/SDL.h>

class Segment {
private:
    Segment *next;
};

class Snake {
public:
    Snake();
    void CheckDirection();
    void Move(int newx, int newy);
    void Eat();
    void Draw();
    void Print();

    SDL_Rect GetHead();
private:
    Segment* head;
    int direction;
    int x, y;
};



class Fruit{ 
public:
    Fruit();

    int *GenerateFruit();
private:
    Segment* fruit;
    int pos[2];
};